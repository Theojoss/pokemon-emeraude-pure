#ifndef GUARD_CONSTANTS_ASYNC_CODE_BATTLE_H
#define GUARD_CONSTANTS_ASYNC_CODE_BATTLE_H

// TRAINER_ASYNC_CODE_BATTLE sentinel lives in constants/trainers.h, alongside
// TRAINER_SECRET_BASE / TRAINER_LINK_OPPONENT / TRAINER_UNION_ROOM, and is
// grouped with them in IsSpecialTrainer() (include/data.h) - never a real
// index into gTrainers[].

// Character-based code: single continuous text-entry screen, 32-symbol
// alphabet (A-Z + 3 digits, deliberately no space - see sAsyncCodeCharset in
// async_code_battle.c), 5 bits/char, one keyboard page, no page-swapping.
#define ASYNC_CODE_ALPHABET_SIZE  32
#define ASYNC_CODE_BITS_PER_CHAR  5   // log2(ASYNC_CODE_ALPHABET_SIZE)
#define ASYNC_CODE_CHAR_COUNT     24  // total characters the player types
#define ASYNC_CODE_TOTAL_BITS     (ASYNC_CODE_CHAR_COUNT * ASYNC_CODE_BITS_PER_CHAR) // 120

#define ASYNC_CODE_MON_COUNT      6   // full team, no more 3-of-6 selection needed
#define ASYNC_CODE_NAME_LENGTH    7   // characters, same alphabet as the rest of the code

// Field widths, in bits, within the decoded bitstream (see async_code_battle.c for exact layout)
#define ASYNC_CODE_NAME_BITS      35 // 7 chars * 5 bits
#define ASYNC_CODE_SEX_BITS       1
// 11 bits (not 9) to cover every species ID in this hack, including custom
// Mega/Gen6+ entries up to SPECIES_CUSTOM_END (see include/constants/species.h,
// NUM_SPECIES is ~1573) - 9 bits (max 511) would silently truncate/collide
// any species ID above 511. This trades checksum strength for correctness:
// see ASYNC_CODE_CHECKSUM_BITS below (12 bits instead of 24 - still catches
// ~4095/4096 typos, see the design discussion this traded off against).
#define ASYNC_CODE_SPECIES_BITS   11
#define ASYNC_CODE_SHINY_BITS     1
#define ASYNC_CODE_MON_BITS       (ASYNC_CODE_SPECIES_BITS + ASYNC_CODE_SHINY_BITS) // no moveset - CreateMon's own level-up moveset is used
#define ASYNC_CODE_CHECKSUM_BITS  (ASYNC_CODE_TOTAL_BITS - ASYNC_CODE_NAME_BITS - ASYNC_CODE_SEX_BITS - ASYNC_CODE_MON_BITS * ASYNC_CODE_MON_COUNT) // 12

#endif // GUARD_CONSTANTS_ASYNC_CODE_BATTLE_H
