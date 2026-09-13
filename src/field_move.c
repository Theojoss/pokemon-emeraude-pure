#include "global.h"
#include "event_data.h"
#include "field_move.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "party_menu.h"
#include "pokemon.h"
#include "constants/field_move.h"
#include "constants/flags.h"
#include "constants/moves.h"
#include "constants/party_menu.h"

static bool32 IsFieldMoveUnlocked_Cut(void)
{
    if (IS_FRLG)
        return FlagGet(FLAG_BADGE02_GET);

    return FlagGet(FLAG_BADGE01_GET);
}

static bool32 IsFieldMoveUnlocked_Flash(void)
{
    if (IS_FRLG)
        return FlagGet(FLAG_BADGE01_GET);

    return FlagGet(FLAG_BADGE02_GET);
}

static bool32 IsFieldMoveUnlocked_RockSmash(void)
{
    if (IS_FRLG)
        return FlagGet(FLAG_BADGE06_GET);

    return FlagGet(FLAG_BADGE03_GET);
}

static bool32 IsFieldMoveUnlocked_Strength(void)
{
    return FlagGet(FLAG_BADGE04_GET);
}

static bool32 IsFieldMoveUnlocked_Surf(void)
{
    return FlagGet(FLAG_BADGE05_GET);
}

static bool32 IsFieldMoveUnlocked_Fly(void)
{
    if (IS_FRLG)
        return FlagGet(FLAG_BADGE03_GET);

    return FlagGet(FLAG_BADGE06_GET);
}

static bool32 IsFieldMoveUnlocked_Dive(void)
{
    return FlagGet(FLAG_BADGE07_GET);
}

static bool32 IsFieldMoveUnlocked_Waterfall(void)
{
    if (IS_FRLG)
        return FlagGet(FLAG_BADGE07_GET);

    return FlagGet(FLAG_BADGE08_GET);
}

static bool32 IsFieldMoveUnlocked_RockClimb(void)
{
    return OW_ROCK_CLIMB_FIELD_MOVE;
}

static bool32 IsFieldMoveUnlocked_Teleport(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Dig(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SecretPower(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_MilkDrink(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SoftBoiled(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SweetScent(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Defog(void)
{
    return OW_DEFOG_FIELD_MOVE;
}

const struct FieldMoveInfo gFieldMoveInfo[FIELD_MOVES_COUNT] =
{
    [FIELD_MOVE_CUT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Cut,
        .isUnlockedFunc = IsFieldMoveUnlocked_Cut,
        .moveID = MOVE_CUT,
        .partyMsgID = PARTY_MSG_NOTHING_TO_CUT,
        .receivedFlag = FLAG_RECEIVED_HM_CUT,
        .overworldCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_FLASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Flash,
        .isUnlockedFunc = IsFieldMoveUnlocked_Flash,
        .moveID = MOVE_FLASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        // Flash is never triggered by an overworld A-press interaction, only
        // from the party menu, so only the menu capability check applies.
        .receivedFlag = FLAG_RECEIVED_HM_FLASH,
        .menuCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_ROCK_SMASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockSmash,
        .isUnlockedFunc = IsFieldMoveUnlocked_RockSmash,
        .moveID = MOVE_ROCK_SMASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .receivedFlag = FLAG_RECEIVED_HM_ROCK_SMASH,
        .overworldCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_STRENGTH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Strength,
        .isUnlockedFunc = IsFieldMoveUnlocked_Strength,
        .moveID = MOVE_STRENGTH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .receivedFlag = FLAG_RECEIVED_HM_STRENGTH,
        .overworldCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_SURF] =
    {
        .fieldMoveFunc = SetUpFieldMove_Surf,
        .isUnlockedFunc = IsFieldMoveUnlocked_Surf,
        .moveID = MOVE_SURF,
        .partyMsgID = PARTY_MSG_CANT_SURF_HERE,
        // Surf already has an overworld A-press trigger (facing water), so
        // unlike Fly/Flash/Dive the party-menu action still requires actually
        // knowing the move.
        .receivedFlag = FLAG_RECEIVED_HM_SURF,
        .overworldCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_FLY] =
    {
        .fieldMoveFunc = SetUpFieldMove_Fly,
        .isUnlockedFunc = IsFieldMoveUnlocked_Fly,
        .moveID = MOVE_FLY,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        // Fly has no overworld A-press trigger at all, so the party-menu
        // capability check is the only way to use it without teaching it.
        .receivedFlag = FLAG_RECEIVED_HM_FLY,
        .menuCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_DIVE] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dive,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dive,
        .moveID = MOVE_DIVE,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .receivedFlag = FLAG_RECEIVED_HM_DIVE,
        .overworldCapabilityCheck = TRUE,
        .menuCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_WATERFALL] =
    {
        .fieldMoveFunc = SetUpFieldMove_Waterfall,
        .isUnlockedFunc = IsFieldMoveUnlocked_Waterfall,
        .moveID = MOVE_WATERFALL,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .receivedFlag = FLAG_RECEIVED_HM_WATERFALL,
        .overworldCapabilityCheck = TRUE,
    },

    [FIELD_MOVE_TELEPORT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Teleport,
        .isUnlockedFunc = IsFieldMoveUnlocked_Teleport,
        .moveID = MOVE_TELEPORT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dig,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dig,
        .moveID = MOVE_DIG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SECRET_POWER] =
    {
        .fieldMoveFunc = SetUpFieldMove_SecretPower,
        .isUnlockedFunc = IsFieldMoveUnlocked_SecretPower,
        .moveID = MOVE_SECRET_POWER,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_MILK_DRINK] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_MilkDrink,
        .moveID = MOVE_MILK_DRINK,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SOFT_BOILED] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_SoftBoiled,
        .moveID = MOVE_SOFT_BOILED,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SWEET_SCENT] =
    {
        .fieldMoveFunc = SetUpFieldMove_SweetScent,
        .isUnlockedFunc = IsFieldMoveUnlocked_SweetScent,
        .moveID = MOVE_SWEET_SCENT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
    [FIELD_MOVE_ROCK_CLIMB] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockClimb,
        .isUnlockedFunc = IsFieldMoveUnlocked_RockClimb,
        .moveID = MOVE_ROCK_CLIMB,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
    [FIELD_MOVE_DEFOG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Defog,
        .isUnlockedFunc = IsFieldMoveUnlocked_Defog,
        .moveID = MOVE_DEFOG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
};

// Finds the first party Pokémon that can be used for this field move on the
// overworld. Once the associated HM has been received (receivedFlag set), any
// party member whose species is capable of learning the move counts, even if
// it doesn't currently know it — mirroring how HMs work in newer games where
// carrying a compatible Pokémon is enough. Field moves without a receivedFlag
// (and any given move before its HM has been received) still require a party
// member to actually know the move, same as the party-menu "use move" action.
bool32 FieldMove_TryGetPartyUser(enum FieldMove fieldMove, u8 *partyIndex, enum Species *species)
{
    enum Move move = FieldMove_GetMoveId(fieldMove);
    u16 receivedFlag = FieldMove_GetReceivedFlag(fieldMove);
    bool32 useCapabilityCheck = (gFieldMoveInfo[fieldMove].overworldCapabilityCheck && receivedFlag != 0 && FlagGet(receivedFlag));

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        enum Species monSpecies = GetMonData(mon, MON_DATA_SPECIES);

        if (monSpecies == SPECIES_NONE)
            break;
        if (GetMonData(mon, MON_DATA_IS_EGG))
            continue;
        if (useCapabilityCheck ? CanLearnTeachableMove(monSpecies, move) : MonKnowsMove(mon, move))
        {
            *partyIndex = i;
            *species = monSpecies;
            return TRUE;
        }
    }
    return FALSE;
}
