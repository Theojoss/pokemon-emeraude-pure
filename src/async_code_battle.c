#include "global.h"
#include "async_code_battle.h"
#include "battle.h"
#include "battle_setup.h"
#include "constants/characters.h"
#include "constants/event_objects.h"
#include "constants/items.h"
#include "data/async_code_battle_sprite_pairs.h"
#include "pokemon.h"
#include "script_pokemon_util.h"

// Bit layout of the 120-bit stream (24 chars * 5 bits), MSB-first, in this
// order: name (35) | sex (1) | mon0..mon5 (12 each) | checksum (12).
// Per-mon layout (12 bits): species (11) | shiny (1). No moveset - CreateMon's
// own level-up moveset is used instead. The checksum covers every bit before
// it (108 bits) - see ChecksumOf(). 11-bit species (not 9) to cover every
// species ID in this hack (see ASYNC_CODE_SPECIES_BITS) - the tradeoff is a
// shorter, weaker checksum (12 bits: ~1/4096 chance a typo slips through
// undetected, vs 1/16.7M at the old 24 bits). Still comfortably good enough:
// shrinking the code itself to claw back checksum bits was considered and
// rejected - the payload alone (108 bits) already needs ~22 characters, so
// there's very little length to trade for checksum strength.

// 32-symbol code alphabet -> game charset byte (see charmap.txt), and it has
// to be a BIJECTION - every one of the 32 array slots holds a byte value
// that appears nowhere else in this table. AsyncCodeBattle_Encode looks
// entries up by index (index -> byte, for display) and GameCharToCodeIndex
// looks them up by byte (byte -> index, for decoding); if two slots ever
// shared a byte, GameCharToCodeIndex's linear scan would always resolve
// that byte to whichever slot comes first, silently discarding which of
// the two indices was actually meant - corrupting the reconstructed
// bitstream on decode and failing the checksum. (This happened: an earlier
// version filled the last 3 slots with duplicate CHAR_A/B/C instead of
// unique bytes, and every code whose non-name bits happened to land on one
// of those 3 indices - most of them, see below - failed to decode.)
//
// A-Z + '1'/'2'/'3' + '-'/'.'/',' = all 32 slots, every one reachable from
// KBPAGE_LETTERS_UPPER (the naming screen's default page) alone via its own
// dedicated KEYBOARD_CODE layout (see naming_screen.c's
// CurrentPageToKeyboardId), genuinely without ever needing to page-swap.
// '1'/'2'/'3' are the "intended" digits (more memorable to read a code out
// loud than punctuation) - '0' was deliberately skipped: this font renders
// '0' and capital 'O' identically. '-'/'.'/',' fill out the remaining 3
// slots; they're not meant to be chosen when a player is just improvising a
// code to send someone, but a legitimately generated one can and does
// contain them (see next paragraph), so they're still real, typeable keys
// on KEYBOARD_CODE, not just filler. KEYBOARD_CODE's 4 rows must stay in
// sync with this exact 32-symbol table (src/text_input_strings.c's
// gText_NamingScreenKeyboardCode_*).
//
// No space anywhere in this table, on purpose - GenerateAsyncCode
// (src/field_specials.c) replaces any real space in the player's name with
// '1' before encoding, but that alone wouldn't be enough on its own: past
// the name, the code's 24 displayed characters are just a raw
// 5-bit-at-a-time slice of the sex/species/shiny/checksum bitstream, not
// aligned to the fields that produced them, so ANY of those bits can
// coincidentally land on any of the 32 possible index values here - purely
// as a side effect of which species are in the party, nothing
// GenerateAsyncCode could special-case away (same reasoning is why indices
// 29-31 above need real, unique, typeable characters instead of being left
// "unused": those bits can just as easily land there as anywhere else).
static const u8 sAsyncCodeCharset[ASYNC_CODE_ALPHABET_SIZE] =
{
    0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, // A-M
    0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, // N-Z
    CHAR_1,
    CHAR_2,
    CHAR_3,
    // These 3 have to be genuinely unique bytes, not reused letters - an
    // earlier version filled these with duplicate CHAR_A/B/C, which broke
    // decoding: GameCharToCodeIndex's linear scan always resolves a byte to
    // its FIRST occurrence, so a byte reused here would always decode back
    // to the real letter's index (0/1/2), never this one, corrupting the
    // reconstructed bitstream and failing the checksum on ANY code that
    // happened to use one of these 3 indices - which is most of them (3/32
    // chance per non-name character, over 17 such characters). '-'/'.'/','
    // are also on KEYBOARD_CODE (see naming_screen.c) specifically so a
    // code that does land on one of these is still actually re-typeable.
    CHAR_HYPHEN, CHAR_PERIOD, CHAR_COMMA,
};

static u32 GameCharToCodeIndex(u8 c)
{
    u32 i;
    for (i = 0; i < ASYNC_CODE_ALPHABET_SIZE; i++)
        if (sAsyncCodeCharset[i] == c)
            return i;
    return 0; // not in our alphabet (player switched keyboard page) - checksum will reject it
}

static void WriteBits(u8 *buffer, u32 *bitPos, u32 value, u32 numBits)
{
    u32 i;
    for (i = 0; i < numBits; i++)
    {
        u32 bit = (value >> (numBits - 1 - i)) & 1;
        u32 pos = *bitPos + i;
        if (bit)
            buffer[pos / 8] |= (0x80 >> (pos % 8));
    }
    *bitPos += numBits;
}

static u32 ReadBits(const u8 *buffer, u32 *bitPos, u32 numBits)
{
    u32 i;
    u32 value = 0;
    for (i = 0; i < numBits; i++)
    {
        u32 pos = *bitPos + i;
        u32 bit = (buffer[pos / 8] >> (7 - (pos % 8))) & 1;
        value = (value << 1) | bit;
    }
    *bitPos += numBits;
    return value;
}

#define ASYNC_CODE_BUFFER_BYTES ((ASYNC_CODE_TOTAL_BITS + 7) / 8)

static void PackCodeToBuffer(const u8 *typedCode, u8 buffer[ASYNC_CODE_BUFFER_BYTES])
{
    u32 i;
    u32 bitPos = 0;
    memset(buffer, 0, ASYNC_CODE_BUFFER_BYTES);
    for (i = 0; i < ASYNC_CODE_CHAR_COUNT; i++)
        WriteBits(buffer, &bitPos, GameCharToCodeIndex(typedCode[i]), ASYNC_CODE_BITS_PER_CHAR);
}

u32 AsyncCodeBattle_HashCode(const u8 *typedCode)
{
    // FNV-1a over the packed bitstream bytes - one hash, reused everywhere
    // (sprite pick, IVs/ability/held item/personality, music pick).
    u8 buffer[ASYNC_CODE_BUFFER_BYTES];
    u32 i;
    u32 hash = 2166136261u;
    PackCodeToBuffer(typedCode, buffer);
    for (i = 0; i < ASYNC_CODE_BUFFER_BYTES; i++)
    {
        hash ^= buffer[i];
        hash *= 16777619u;
    }
    return hash;
}

static u32 ChecksumOf(const u8 buffer[ASYNC_CODE_BUFFER_BYTES], u32 payloadBits)
{
    // Same FNV-1a construction as AsyncCodeBattle_HashCode, but only over the
    // payload bits (name+sex+mons), truncated to ASYNC_CODE_CHECKSUM_BITS.
    // Deliberately a distinct seed from AsyncCodeBattle_HashCode so a typo
    // that happens to preserve the flavor hash doesn't also fool the checksum.
    //
    // payloadBits (108) isn't a multiple of 8, so the last payload byte's
    // low `extraBits` bits are shared with the checksum's own first bits
    // once the full 120-bit stream is packed. Those bits are still zero
    // when this is called from AsyncCodeBattle_Encode (checksum not written
    // into buffer yet) but hold real checksum bits when called from
    // AsyncCodeBattle_TryDecode (PackCodeToBuffer already reconstructed the
    // whole stream first, checksum included, before this runs) - masking
    // them out here keeps both call sites hashing the exact same bits.
    // Without this, a genuinely valid, unmodified code would never pass its
    // own checksum check (payloadBits was a clean multiple of 8 - and this
    // masking a no-op - before ASYNC_CODE_SPECIES_BITS went from 9 to 11).
    u32 payloadBytes = (payloadBits + 7) / 8;
    u32 extraBits = payloadBytes * 8 - payloadBits;
    u32 hash = 84696351u;
    u32 i;
    for (i = 0; i < payloadBytes - 1; i++)
    {
        hash ^= buffer[i];
        hash *= 16777619u;
    }
    hash ^= buffer[payloadBytes - 1] & (u8)(0xFF << extraBits);
    hash *= 16777619u;
    return hash & ((1u << ASYNC_CODE_CHECKSUM_BITS) - 1);
}

bool32 AsyncCodeBattle_TryDecode(const u8 *typedCode, struct AsyncCodeBattleTrainer *out)
{
    u8 buffer[ASYNC_CODE_BUFFER_BYTES];
    u32 bitPos = 0;
    u32 payloadBits = ASYNC_CODE_TOTAL_BITS - ASYNC_CODE_CHECKSUM_BITS;
    u32 expectedChecksum;
    u32 actualChecksum;
    u32 i;
    struct AsyncCodeBattleTrainer decoded = {0};

    PackCodeToBuffer(typedCode, buffer);

    // Name (7 chars, 32-symbol alphabet -> game charset)
    for (i = 0; i < ASYNC_CODE_NAME_LENGTH; i++)
    {
        u32 charIndex = ReadBits(buffer, &bitPos, ASYNC_CODE_BITS_PER_CHAR);
        decoded.trainerName[i] = sAsyncCodeCharset[charIndex];
    }
    decoded.trainerName[ASYNC_CODE_NAME_LENGTH] = EOS;
    // Strip trailing '1' padding (see GenerateAsyncCode, src/field_specials.c -
    // short names are padded with CHAR_1, not space, so the printed code has
    // no invisible characters) so a short name displays as itself ("THEO"),
    // not with its padding visible ("THEO111"), to whoever receives the code.
    for (i = ASYNC_CODE_NAME_LENGTH; i > 0 && decoded.trainerName[i - 1] == CHAR_1; i--)
        decoded.trainerName[i - 1] = EOS;

    // Sex
    decoded.sex = ReadBits(buffer, &bitPos, ASYNC_CODE_SEX_BITS);

    // 6 Pokémon (species + shiny, no moveset)
    for (i = 0; i < ASYNC_CODE_MON_COUNT; i++)
    {
        decoded.mons[i].species = ReadBits(buffer, &bitPos, ASYNC_CODE_SPECIES_BITS);
        decoded.mons[i].shiny = ReadBits(buffer, &bitPos, ASYNC_CODE_SHINY_BITS);
    }

    expectedChecksum = ReadBits(buffer, &bitPos, ASYNC_CODE_CHECKSUM_BITS);
    actualChecksum = ChecksumOf(buffer, payloadBits);

    if (expectedChecksum != actualChecksum)
        return FALSE;

    *out = decoded;
    return TRUE;
}

static u8 ToUpperGameChar(u8 c)
{
    // sAsyncCodeCharset only has uppercase letters - the player's own saved
    // name can be lowercase (naming screen isn't restricted to one page like
    // NAMING_SCREEN_CODE is), so GenerateAsyncCode (src/field_specials.c)
    // needs this before handing name bytes to GameCharToCodeIndex, or every
    // lowercase letter would silently fall back to index 0 ('A').
    if (c >= CHAR_a && c <= CHAR_z)
        return c - CHAR_a + CHAR_A;
    return c;
}

// Reverse of AsyncCodeBattle_TryDecode: packs a trainer definition (built by
// the caller from the player's own save data - see GenerateAsyncCode in
// src/field_specials.c) into a checksummed 24-character code, ready to be
// read back out by AsyncCodeBattle_TryDecode on a friend's copy of the game.
// outTypedCode must have room for ASYNC_CODE_CHAR_COUNT + 1 bytes (EOS-terminated,
// same game-charset format as AsyncCodeBattle_TryDecode's typedCode input).
void AsyncCodeBattle_Encode(const struct AsyncCodeBattleTrainer *trainer, u8 *outTypedCode)
{
    u8 buffer[ASYNC_CODE_BUFFER_BYTES];
    u32 bitPos = 0;
    u32 payloadBits = ASYNC_CODE_TOTAL_BITS - ASYNC_CODE_CHECKSUM_BITS;
    u32 checksum;
    u32 i;

    memset(buffer, 0, sizeof(buffer));

    // Name (7 chars, game charset -> 32-symbol alphabet). trainer->trainerName
    // is expected to already be space-padded to ASYNC_CODE_NAME_LENGTH by the
    // caller (a shorter EOS-terminated name would otherwise read past EOS).
    for (i = 0; i < ASYNC_CODE_NAME_LENGTH; i++)
        WriteBits(buffer, &bitPos, GameCharToCodeIndex(ToUpperGameChar(trainer->trainerName[i])), ASYNC_CODE_BITS_PER_CHAR);

    // Sex
    WriteBits(buffer, &bitPos, trainer->sex, ASYNC_CODE_SEX_BITS);

    // 6 Pokémon (species + shiny, no moveset - see struct AsyncCodeMon)
    for (i = 0; i < ASYNC_CODE_MON_COUNT; i++)
    {
        WriteBits(buffer, &bitPos, trainer->mons[i].species, ASYNC_CODE_SPECIES_BITS);
        WriteBits(buffer, &bitPos, trainer->mons[i].shiny, ASYNC_CODE_SHINY_BITS);
    }

    checksum = ChecksumOf(buffer, payloadBits);
    WriteBits(buffer, &bitPos, checksum, ASYNC_CODE_CHECKSUM_BITS);

    // Unpack the freshly-written 120-bit stream back into 24 displayable
    // characters - same bit layout AsyncCodeBattle_TryDecode reads, just
    // produced instead of consumed.
    bitPos = 0;
    for (i = 0; i < ASYNC_CODE_CHAR_COUNT; i++)
    {
        u32 charIndex = ReadBits(buffer, &bitPos, ASYNC_CODE_BITS_PER_CHAR);
        outTypedCode[i] = sAsyncCodeCharset[charIndex];
    }
    outTypedCode[ASYNC_CODE_CHAR_COUNT] = EOS;
}

// Stashed here (not yet in gBattleResources - that struct doesn't exist until
// CB2_InitBattle starts allocating it) between the moment the player confirms
// a valid code and the moment BattleSetup_StartAsyncCodeBattle() gets called.
// AllocateBattleResources() reads this back to fill gBattleResources->asyncCodeBattle.
static struct AsyncCodeBattleTrainer sPendingAsyncTrainer;
static u32 sPendingAsyncHash;

void AsyncCodeBattle_Start(const struct AsyncCodeBattleTrainer *trainer, u32 hash)
{
    sPendingAsyncTrainer = *trainer;
    sPendingAsyncHash = hash;
    BattleSetup_StartAsyncCodeBattle();
}

const struct AsyncCodeBattleTrainer *GetPendingAsyncCodeBattleTrainer(void)
{
    return &sPendingAsyncTrainer;
}

u32 GetPendingAsyncCodeBattleHash(void)
{
    return sPendingAsyncHash;
}

// Small curated pool of sensible battle items - not exhaustive, just enough
// variety for a deterministic pick (hash % pool size). ITEM_NONE included on
// purpose (some opponents simply hold nothing).
static const enum Item sAsyncBattleHeldItems[] =
{
    ITEM_NONE,
    ITEM_LEFTOVERS,
    ITEM_LIFE_ORB,
    ITEM_CHOICE_BAND,
    ITEM_CHOICE_SPECS,
    ITEM_CHOICE_SCARF,
    ITEM_ASSAULT_VEST,
    ITEM_SITRUS_BERRY,
    ITEM_FOCUS_SASH,
};

static u32 GetAveragePlayerPartyLevel(void)
{
    u32 i;
    u32 count = CalculatePlayerPartyCount();
    u32 total = 0;

    if (count == 0)
        return 5; // no party at all (shouldn't happen) - don't divide by zero

    for (i = 0; i < count; i++)
        total += GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_LEVEL);

    return total / count;
}

void BuildAsyncOpponentParty(const struct AsyncCodeBattleTrainer *trainer, u32 hash)
{
    u32 i;
    u32 level = GetAveragePlayerPartyLevel();

    // Mirrors CreateSecretBaseEnemyParty: stash the resolved resource (decoded
    // trainer, hash, sprite pair) before building the party from it.
    gBattleResources->asyncCodeBattle->decoded = *trainer;
    gBattleResources->asyncCodeBattle->hash = hash;
    GetAsyncBattleSpritePair(trainer->sex, hash,
        &gBattleResources->asyncCodeBattle->overworldGfxId,
        &gBattleResources->asyncCodeBattle->trainerPicId);

    ZeroEnemyPartyMons();

    for (i = 0; i < ASYNC_CODE_MON_COUNT; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_OPPONENT_A][i];
        // Distinct per-mon derivation from the same code hash - never a live RNG call.
        u32 monHash = hash ^ (i * 0x9E3779B9u);
        u32 personality = monHash;
        u32 packedIvs = (monHash & 0x1F)               // HP
                       | (((monHash >> 5) & 0x1F) << 5)  // Attack
                       | (((monHash >> 10) & 0x1F) << 10) // Defense
                       | (((monHash >> 15) & 0x1F) << 15) // Speed
                       | (((monHash >> 20) & 0x1F) << 20) // Sp. Attack
                       | (((monHash >> 25) & 0x1F) << 25); // Sp. Defense
        u8 abilityNum = (monHash >> 30) & 1;
        enum Item heldItem = sAsyncBattleHeldItems[monHash % ARRAY_COUNT(sAsyncBattleHeldItems)];
        bool8 shiny = trainer->mons[i].shiny;

        CreateMon(mon, trainer->mons[i].species, level, personality, OTID_STRUCT_RANDOM_NO_SHINY);
        SetMonData(mon, MON_DATA_IVS, &packedIvs);
        SetMonData(mon, MON_DATA_ABILITY_NUM, &abilityNum);
        CalculateMonStats(mon);
        // No explicit moveset in the code - GiveMonInitialMoveset() assigns
        // the species' own level-up movepool, exactly what every other
        // CreateMon-family helper in pokemon.c already does automatically
        // right after CalculateMonStats (CreateMon itself is the one
        // exception that leaves moves empty).
        GiveMonInitialMoveset(mon);

        SetMonData(mon, MON_DATA_IS_SHINY, &shiny);
        SetMonData(mon, MON_DATA_HELD_ITEM, &heldItem);
    }
}

void RestorePartyAfterAsyncCodeBattle(void)
{
    // No stakes to this battle (no EXP/money either) - the team comes out
    // exactly as it went in, not carrying fainted/HP/PP/status from the
    // fight. Full team was used directly (no 3-of-6 reduction needed now
    // that this is a straight 6v6), so a plain heal is all that's needed.
    HealPlayerParty();
}

void GetAsyncBattleSpritePair(u8 sex, u32 hash, u16 *owGfxId, enum TrainerPicID *picId)
{
    const struct AsyncBattleSpritePair *pool;
    u32 poolSize;
    u32 index;

    if (sex == MALE)
    {
        pool = sAsyncBattleSpritePairs_Male;
        poolSize = ARRAY_COUNT(sAsyncBattleSpritePairs_Male);
    }
    else
    {
        pool = sAsyncBattleSpritePairs_Female;
        poolSize = ARRAY_COUNT(sAsyncBattleSpritePairs_Female);
    }

    index = hash % poolSize;
    *owGfxId = pool[index].overworldGfxId;
    *picId = pool[index].picId;
}
