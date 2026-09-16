#ifndef GUARD_ASYNC_CODE_BATTLE_H
#define GUARD_ASYNC_CODE_BATTLE_H

#include "constants/async_code_battle.h"
#include "constants/global.h"
#include "constants/pokemon.h"
#include "constants/species.h"
#include "constants/trainers.h"

struct AsyncCodeMon
{
    enum Species species;
    bool8 shiny;
    // No moveset: CreateMon()'s own level-up-based default moveset is used
    // instead (see BuildAsyncOpponentParty).
};

struct AsyncCodeBattleTrainer
{
    u8 trainerName[ASYNC_CODE_NAME_LENGTH + 1]; // game-charset encoded, null-terminated
    u8 sex; // MALE / FEMALE
    struct AsyncCodeMon mons[ASYNC_CODE_MON_COUNT];
};

// Resource allocated alongside gBattleResources->secretBase, filled by
// BuildAsyncOpponentParty() (src/battle_util2.c hook) from the struct below
// plus the deterministic hash. Modeled on struct SecretBase (include/global.h)
// but carries what a procedural opponent actually needs: a real name, sex,
// and a resolved sprite pair (SecretBase can't - see plan for details).
struct AsyncBattleResource
{
    struct AsyncCodeBattleTrainer decoded;
    u32 hash;
    u16 overworldGfxId;
    enum TrainerPicID trainerPicId;
};

// Decodes ASYNC_CODE_CHAR_COUNT (24) typed characters (game-charset encoded,
// e.g. straight out of a naming-screen destBuffer) into a trainer definition.
// Returns FALSE (out left untouched) if the checksum doesn't match - caller
// should tell the player the code is invalid / no trainer found.
bool32 AsyncCodeBattle_TryDecode(const u8 *typedCode, struct AsyncCodeBattleTrainer *out);

// Reverse of AsyncCodeBattle_TryDecode - packs trainer into a checksummed,
// EOS-terminated ASYNC_CODE_CHAR_COUNT-character code. outTypedCode must have
// room for ASYNC_CODE_CHAR_COUNT + 1 bytes. See GenerateAsyncCode
// (src/field_specials.c) for how trainer is built from the player's own save data.
void AsyncCodeBattle_Encode(const struct AsyncCodeBattleTrainer *trainer, u8 *outTypedCode);

// Deterministic hash of the raw typed code. Same code -> same hash always.
// Used to derive: sprite pair, per-mon IVs/ability/held item/personality, music.
u32 AsyncCodeBattle_HashCode(const u8 *typedCode);

// Entry point once a code has been validated: builds the opponent party and
// starts the battle. See src/battle_setup.c BattleSetup_StartAsyncCodeBattle.
void AsyncCodeBattle_Start(const struct AsyncCodeBattleTrainer *trainer, u32 hash);

// Heals the player's party after an async code battle (no stakes to this
// fight - see CB2_EndTrainerBattle in src/battle_setup.c).
void RestorePartyAfterAsyncCodeBattle(void);

// Builds gParties[B_TRAINER_OPPONENT_A] from the decoded trainer + hash. Called
// from AllocateBattleResources() (src/battle_util2.c) when BATTLE_TYPE_ASYNC_CODE_BATTLE
// is set. Level is the player's current average party level (not encoded in
// the code); IVs/ability/held item/personality are deterministic per hash.
void BuildAsyncOpponentParty(const struct AsyncCodeBattleTrainer *trainer, u32 hash);

// Read back by AllocateBattleResources() (src/battle_util2.c, Phase 2) to fill
// gBattleResources->asyncCodeBattle once it's allocated.
const struct AsyncCodeBattleTrainer *GetPendingAsyncCodeBattleTrainer(void);
u32 GetPendingAsyncCodeBattleHash(void);

// Deterministic pick from the 52-pair sprite pool (src/data/async_code_battle_sprite_pairs.h),
// split by sex - same hash always yields the same pair.
void GetAsyncBattleSpritePair(u8 sex, u32 hash, u16 *owGfxId, enum TrainerPicID *picId);

#endif // GUARD_ASYNC_CODE_BATTLE_H
