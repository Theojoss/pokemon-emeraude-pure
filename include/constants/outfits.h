#ifndef GUARD_CONSTANTS_OUTFITS_H
#define GUARD_CONSTANTS_OUTFITS_H

// ScrCmd_getoutfitstatus
#define OUTFIT_CHECK_FLAG 0
#define OUTFIT_CHECK_USED 1
// ScrCmd_toggleoutfit
#define OUTFIT_TOGGLE_UNLOCK 0
#define OUTFIT_TOGGLE_LOCK 1
// BufferOutfitStrings
#define OUTFIT_BUFFER_NAME 0
#define OUTFIT_BUFFER_DESC 1

// outfits
#define OUTFIT_NONE        0
#define OUTFIT_DEFAULT     1
#define OUTFIT_KANTO       2
#define OUTFIT_GOLD        3
#define OUTFIT_HOENN       4
#define OUTFIT_SINNOH      5
#define OUTFIT_TEAM_ROCKET 6
#define OUTFIT_TEAM_MAGMA  7
#define OUTFIT_ANIME       8
#define OUTFIT_KANTO_RIVAL       9
#define OUTFIT_COUNT       10

// inclusive
#define OUTFIT_BEGIN OUTFIT_DEFAULT
#define OUTFIT_END   OUTFIT_KANTO_RIVAL

#define DEFAULT_OUTFIT OUTFIT_DEFAULT

#endif // GUARD_CONSTANTS_OUTFITS_H
