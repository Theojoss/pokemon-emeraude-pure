#ifndef GUARD_NUZLOCKE_H
#define GUARD_NUZLOCKE_H

#include "pokemon.h"

// Is the Nuzlocke Challenge active on this save?
bool8 IsNuzlockeActive(void);

// Dead (permanently fainted) Pokémon
bool8 IsMonDead(struct Pokemon *mon);
bool8 IsBoxMonDead(struct BoxPokemon *boxMon);

// Hooked from SetMonData/DoWhiteOut to mark Pokémon as dead once their HP hits 0
void NuzlockeHandleFaint(struct Pokemon *mon);
void NuzlockeHandleWhiteout(void);

// First Encounter / Duplicate / Shiny clause
bool8 NuzlockeCanCatchPokemon(u16 species, bool8 isShiny);
void NuzlockeOnWildEncounterStart(u16 species, bool8 isShiny);
void NuzlockeMarkLocationEncountered(void);
bool8 NuzlockeIsFirstEncounterHere(void);

// Silent save used when the player disables Nuzlocke mode after a whiteout
void NuzlockeSilentSave(void);

// Any usable (non-egg, non-dead) Pokémon left anywhere (party or PC)? Used to force-disable Nuzlocke
// after a whiteout if refusing to disable would otherwise softlock the player with no viable Pokémon.
bool8 NuzlockeHasAnyLivingPokemon(void);

#endif // GUARD_NUZLOCKE_H
