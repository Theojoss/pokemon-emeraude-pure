#include "global.h"
#include "nuzlocke.h"
#include "event_data.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "overworld.h"
#include "battle.h"
#include "save.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/region_map_sections.h"

// Every MAPSEC that actually has a wild encounter table (Hoenn + Kanto + Battle Frontier),
// underwater variants folded into their surface route. Generated from src/data/wild_encounters.json.
// Index in this array is the Nuzlocke "first encounter" bit position (see sNuzlockeEncounterVars).
static const u16 sNuzlockeTrackedLocations[] =
{
    MAPSEC_ABANDONED_SHIP, MAPSEC_ALTERING_CAVE, MAPSEC_ALTERING_CAVE_FRLG, MAPSEC_ARTISAN_CAVE,
    MAPSEC_BERRY_FOREST, MAPSEC_BOND_BRIDGE, MAPSEC_CANYON_ENTRANCE, MAPSEC_CAPE_BRINK,
    MAPSEC_CAVE_OF_ORIGIN, MAPSEC_CELADON_CITY, MAPSEC_CERULEAN_CAVE, MAPSEC_CERULEAN_CITY,
    MAPSEC_CINNABAR_ISLAND, MAPSEC_DESERT_UNDERPASS, MAPSEC_DEWFORD_TOWN, MAPSEC_DIGLETTS_CAVE,
    MAPSEC_DILFORD_CHAMBER, MAPSEC_EVER_GRANDE_CITY, MAPSEC_FIERY_PATH, MAPSEC_FIVE_ISLAND,
    MAPSEC_FIVE_ISLE_MEADOW, MAPSEC_FOUR_ISLAND, MAPSEC_FUCHSIA_CITY, MAPSEC_GRANITE_CAVE,
    MAPSEC_GREEN_PATH, MAPSEC_ICEFALL_CAVE, MAPSEC_JAGGED_PASS, MAPSEC_KANTO_SAFARI_ZONE,
    MAPSEC_KANTO_VICTORY_ROAD, MAPSEC_KINDLE_ROAD, MAPSEC_LILYCOVE_CITY, MAPSEC_LIPTOO_CHAMBER,
    MAPSEC_LOST_CAVE, MAPSEC_MAGMA_HIDEOUT, MAPSEC_MEMORIAL_PILLAR, MAPSEC_METEOR_FALLS,
    MAPSEC_MIRAGE_TOWER, MAPSEC_MONEAN_CHAMBER, MAPSEC_MOSSDEEP_CITY, MAPSEC_MT_EMBER,
    MAPSEC_MT_MOON, MAPSEC_MT_PYRE, MAPSEC_NEW_MAUVILLE, MAPSEC_ONE_ISLAND,
    MAPSEC_OUTCAST_ISLAND, MAPSEC_PACIFIDLOG_TOWN, MAPSEC_PALLET_TOWN, MAPSEC_PATTERN_BUSH,
    MAPSEC_PETALBURG_CITY, MAPSEC_PETALBURG_WOODS, MAPSEC_POKEMON_MANSION, MAPSEC_POKEMON_TOWER,
    MAPSEC_POWER_PLANT, MAPSEC_RESORT_GORGEOUS, MAPSEC_RIXY_CHAMBER, MAPSEC_ROCK_TUNNEL,
    MAPSEC_ROUTE_1, MAPSEC_ROUTE_10, MAPSEC_ROUTE_101, MAPSEC_ROUTE_102,
    MAPSEC_ROUTE_103, MAPSEC_ROUTE_104, MAPSEC_ROUTE_105, MAPSEC_ROUTE_106,
    MAPSEC_ROUTE_107, MAPSEC_ROUTE_108, MAPSEC_ROUTE_109, MAPSEC_ROUTE_11,
    MAPSEC_ROUTE_110, MAPSEC_ROUTE_111, MAPSEC_ROUTE_112, MAPSEC_ROUTE_113,
    MAPSEC_ROUTE_114, MAPSEC_ROUTE_115, MAPSEC_ROUTE_116, MAPSEC_ROUTE_117,
    MAPSEC_ROUTE_118, MAPSEC_ROUTE_119, MAPSEC_ROUTE_12, MAPSEC_ROUTE_120,
    MAPSEC_ROUTE_121, MAPSEC_ROUTE_122, MAPSEC_ROUTE_123, MAPSEC_ROUTE_124,
    MAPSEC_ROUTE_125, MAPSEC_ROUTE_126, MAPSEC_ROUTE_127, MAPSEC_ROUTE_128,
    MAPSEC_ROUTE_129, MAPSEC_ROUTE_13, MAPSEC_ROUTE_130, MAPSEC_ROUTE_131,
    MAPSEC_ROUTE_132, MAPSEC_ROUTE_133, MAPSEC_ROUTE_134, MAPSEC_ROUTE_14,
    MAPSEC_ROUTE_15, MAPSEC_ROUTE_16, MAPSEC_ROUTE_17, MAPSEC_ROUTE_18,
    MAPSEC_ROUTE_19, MAPSEC_ROUTE_2, MAPSEC_ROUTE_20, MAPSEC_ROUTE_21,
    MAPSEC_ROUTE_22, MAPSEC_ROUTE_23, MAPSEC_ROUTE_24, MAPSEC_ROUTE_25,
    MAPSEC_ROUTE_3, MAPSEC_ROUTE_4, MAPSEC_ROUTE_5, MAPSEC_ROUTE_6,
    MAPSEC_ROUTE_7, MAPSEC_ROUTE_8, MAPSEC_ROUTE_9, MAPSEC_RUIN_VALLEY,
    MAPSEC_RUSTURF_TUNNEL, MAPSEC_SAFARI_ZONE, MAPSEC_SCUFIB_CHAMBER, MAPSEC_SEAFLOOR_CAVERN,
    MAPSEC_SEAFOAM_ISLANDS, MAPSEC_SEVAULT_CANYON, MAPSEC_SHOAL_CAVE, MAPSEC_SKY_PILLAR,
    MAPSEC_SLATEPORT_CITY, MAPSEC_SOOTOPOLIS_CITY, MAPSEC_S_S_ANNE, MAPSEC_TANOBY_RUINS,
    MAPSEC_THREE_ISLE_PORT, MAPSEC_TRAINER_TOWER, MAPSEC_TREASURE_BEACH, MAPSEC_VERMILION_CITY,
    MAPSEC_VIAPOIS_CHAMBER, MAPSEC_VICTORY_ROAD, MAPSEC_VIRIDIAN_CITY, MAPSEC_VIRIDIAN_FOREST,
    MAPSEC_WATER_LABYRINTH, MAPSEC_WATER_PATH, MAPSEC_WEEPTH_CHAMBER,
};

#define NUZLOCKE_LOCATION_COUNT ARRAY_COUNT(sNuzlockeTrackedLocations)

// 9 vars x 16 bits = 144 bits, enough to cover every entry in sNuzlockeTrackedLocations.
static const u16 sNuzlockeEncounterVars[] =
{
    VAR_NUZLOCKE_ENCOUNTERS_1, VAR_NUZLOCKE_ENCOUNTERS_2, VAR_NUZLOCKE_ENCOUNTERS_3,
    VAR_NUZLOCKE_ENCOUNTERS_4, VAR_NUZLOCKE_ENCOUNTERS_5, VAR_NUZLOCKE_ENCOUNTERS_6,
    VAR_NUZLOCKE_ENCOUNTERS_7, VAR_NUZLOCKE_ENCOUNTERS_8, VAR_NUZLOCKE_ENCOUNTERS_9,
};

bool8 IsNuzlockeActive(void)
{
    return FlagGet(FLAG_NUZLOCKE);
}

// Underwater maps share their wild encounter table (and their Nuzlocke "area") with the surface route above them.
static u16 GetNuzlockeLocationId(u16 mapSec)
{
    switch (mapSec)
    {
    case MAPSEC_UNDERWATER_124:
        return MAPSEC_ROUTE_124;
    case MAPSEC_UNDERWATER_126:
        return MAPSEC_ROUTE_126;
    default:
        return mapSec;
    }
}

static s32 GetNuzlockeLocationIndex(u16 mapSec)
{
    u32 i;

    mapSec = GetNuzlockeLocationId(mapSec);
    for (i = 0; i < NUZLOCKE_LOCATION_COUNT; i++)
    {
        if (sNuzlockeTrackedLocations[i] == mapSec)
            return i;
    }
    return -1; // Not a tracked wild-encounter area (e.g. an indoor map) - Nuzlocke rules don't apply there.
}

static bool8 HasEncounteredCurrentLocation(bool8 markEncountered)
{
    s32 index = GetNuzlockeLocationIndex(GetCurrentRegionMapSectionId());
    u32 varIndex, bit, varValue;

    if (index < 0)
        return FALSE;

    varIndex = index / 16;
    bit = index % 16;
    varValue = VarGet(sNuzlockeEncounterVars[varIndex]);

    if (varValue & (1 << bit))
        return TRUE;

    if (markEncountered)
        VarSet(sNuzlockeEncounterVars[varIndex], varValue | (1 << bit));

    return FALSE;
}

static bool8 PlayerOwnsSpecies(u16 species)
{
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES) == species)
            return TRUE;
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(i, j);
            if (GetBoxMonData(boxMon, MON_DATA_SPECIES) == species)
                return TRUE;
        }
    }

    return FALSE;
}

bool8 IsMonDead(struct Pokemon *mon)
{
    if (!IsNuzlockeActive())
        return FALSE; // Disabling the challenge un-bricks every previously "dead" Pokémon

    return GetMonData(mon, MON_DATA_IS_DEAD);
}

bool8 IsBoxMonDead(struct BoxPokemon *boxMon)
{
    if (!IsNuzlockeActive())
        return FALSE;

    return GetBoxMonData(boxMon, MON_DATA_IS_DEAD);
}

void NuzlockeHandleFaint(struct Pokemon *mon)
{
    u32 dead = TRUE;

    if (!IsNuzlockeActive())
        return;

    // Async code battles are explicitly stakes-free (no EXP, no money, full
    // heal after - see RestorePartyAfterAsyncCodeBattle in
    // src/async_code_battle.c) - a mon fainting there must not trigger
    // Nuzlocke permadeath, or "no stakes" would be a lie for anyone running
    // a Nuzlocke save.
    if (gBattleTypeFlags & BATTLE_TYPE_ASYNC_CODE_BATTLE)
        return;

    if (GetMonData(mon, MON_DATA_HP) == 0 && !GetMonData(mon, MON_DATA_SANITY_IS_EGG))
        SetMonData(mon, MON_DATA_IS_DEAD, &dead);
}

void NuzlockeHandleWhiteout(void)
{
    u32 i;
    u32 dead = TRUE;

    if (!IsNuzlockeActive())
        return;

    // See the matching guard in NuzlockeHandleFaint above - async code
    // battles never actually reach a whiteout (see the
    // TRAINER_ASYNC_CODE_BATTLE check around battle_setup.c:1512-1517), but
    // guard here too for the same reason, in case that ever changes.
    if (gBattleTypeFlags & BATTLE_TYPE_ASYNC_CODE_BATTLE)
        return;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE && !GetMonData(mon, MON_DATA_SANITY_IS_EGG))
            SetMonData(mon, MON_DATA_IS_DEAD, &dead);
    }
}

// species/isShiny describe the wild Pokémon the player is trying to throw a ball at.
bool8 NuzlockeCanCatchPokemon(u16 species, bool8 isShiny)
{
    if (!IsNuzlockeActive())
        return TRUE;

    if (isShiny) // Shiny Clause: shinies can always be caught, regardless of the other rules
        return TRUE;

    if (HasEncounteredCurrentLocation(FALSE)) // This area's first encounter was already used up
        return FALSE;

    if (PlayerOwnsSpecies(species)) // Duplicate Clause: don't consume the area, but can't catch it either
        return FALSE;

    return TRUE;
}

// Whether this wild encounter is a genuine, unclaimed "first encounter" for its area - snapshotted
// when the wild Pokémon is created (CreateWildMon), before anything else can change species ownership
// (most notably, before the player might catch it, which would otherwise make PlayerOwnsSpecies() lie
// once checked again at battle end).
static bool8 sCurrentEncounterConsumesArea = FALSE;

void NuzlockeOnWildEncounterStart(u16 species, bool8 isShiny)
{
    // Before the player has their Poké Balls (and the Pokédex, handed over at the same time), any wild
    // encounter is forced - there's no way to catch it, so it must not burn the area's first encounter.
    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        sCurrentEncounterConsumesArea = FALSE;
        return;
    }

    sCurrentEncounterConsumesArea = IsNuzlockeActive() && !isShiny && !PlayerOwnsSpecies(species);
}

// Called once a wild (non-trainer) battle has fully ended, regardless of outcome (caught/defeated/ran/fled/teleported).
void NuzlockeMarkLocationEncountered(void)
{
    if (!IsNuzlockeActive() || (gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return;

    if (!sCurrentEncounterConsumesArea) // Shiny/Duplicate Clause: this encounter doesn't consume the area
        return;

    HasEncounteredCurrentLocation(TRUE);
}

// Used to prevent double wild battles from burning through a still-unused first encounter.
bool8 NuzlockeIsFirstEncounterHere(void)
{
    if (!IsNuzlockeActive())
        return FALSE;

    return !HasEncounteredCurrentLocation(FALSE);
}

void NuzlockeSilentSave(void)
{
    TrySavingData(SAVE_LINK);
}

bool8 NuzlockeHasAnyLivingPokemon(void)
{
    u32 i, j;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        if (GetMonData(mon, MON_DATA_SPECIES) != SPECIES_NONE
            && !GetMonData(mon, MON_DATA_SANITY_IS_EGG)
            && !IsMonDead(mon))
            return TRUE;
    }

    for (i = 0; i < TOTAL_BOXES_COUNT; i++)
    {
        for (j = 0; j < IN_BOX_COUNT; j++)
        {
            struct BoxPokemon *boxMon = GetBoxedMonPtr(i, j);
            if (GetBoxMonData(boxMon, MON_DATA_SPECIES) != SPECIES_NONE
                && !GetBoxMonData(boxMon, MON_DATA_IS_EGG)
                && !IsBoxMonDead(boxMon))
                return TRUE;
        }
    }

    return FALSE;
}
