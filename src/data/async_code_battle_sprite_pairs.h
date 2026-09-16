// Pool of {overworld sprite, battle sprite} pairs for an async code-battle
// opponent, split by sex. Selection is deterministic (index = hash % pool
// size), never a live random draw - see GetAsyncBattleSpritePair().
//
// 38 trainer-class pairs + 14 costume pairs (Team Magma costume excluded on
// purpose: already covered by the Team Magma "Grunt" trainer class below) =
// 52 total, 31 male / 21 female. Built from the sprite reference gallery
// worked out earlier for this feature (trainer_class_lookups.h / event_objects.h
// / outfit_tables.h are the underlying sources for every constant here).

struct AsyncBattleSpritePair
{
    u16 overworldGfxId;
    enum TrainerPicID picId;
};

static const struct AsyncBattleSpritePair sAsyncBattleSpritePairs_Male[] =
{
    // Trainer classes (23)
    {OBJ_EVENT_GFX_HIKER,                TRAINER_PIC_HIKER},
    {OBJ_EVENT_GFX_AQUA_MEMBER_M,         TRAINER_PIC_AQUA_GRUNT_M},
    {OBJ_EVENT_GFX_COOLTRAINER_M,         TRAINER_PIC_COOLTRAINER_M},
    {OBJ_EVENT_GFX_SWIMMER_M,             TRAINER_PIC_SWIMMER_M},
    {OBJ_EVENT_GFX_MAGMA_MEMBER_M,        TRAINER_PIC_MAGMA_GRUNT_M},
    {OBJ_EVENT_GFX_EXPERT_M,              TRAINER_PIC_EXPERT_M},
    {OBJ_EVENT_GFX_BLACK_BELT,            TRAINER_PIC_BLACK_BELT},
    {OBJ_EVENT_GFX_TUBER_M,               TRAINER_PIC_TUBER_M},
    {OBJ_EVENT_GFX_RICH_BOY,              TRAINER_PIC_RICH_BOY},
    {OBJ_EVENT_GFX_MANIAC,                TRAINER_PIC_POKEMANIAC},
    {OBJ_EVENT_GFX_CAMPER,                TRAINER_PIC_CAMPER},
    {OBJ_EVENT_GFX_PSYCHIC_M,             TRAINER_PIC_PSYCHIC_M},
    {OBJ_EVENT_GFX_GENTLEMAN,             TRAINER_PIC_GENTLEMAN},
    {OBJ_EVENT_GFX_SCHOOL_KID_M,          TRAINER_PIC_SCHOOL_KID_M},
    {OBJ_EVENT_GFX_POKEFAN_M,             TRAINER_PIC_POKEFAN_M},
    {OBJ_EVENT_GFX_YOUNGSTER,             TRAINER_PIC_YOUNGSTER},
    {OBJ_EVENT_GFX_FISHERMAN,             TRAINER_PIC_FISHERMAN},
    {OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,  TRAINER_PIC_CYCLING_TRIATHLETE_M},
    {OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,  TRAINER_PIC_RUNNING_TRIATHLETE_M},
    {OBJ_EVENT_GFX_SWIMMER_M,             TRAINER_PIC_SWIMMING_TRIATHLETE_M}, // no dedicated OW sprite, reuses Swimmer
    {OBJ_EVENT_GFX_NINJA_BOY,             TRAINER_PIC_NINJA_BOY},
    {OBJ_EVENT_GFX_SAILOR,                TRAINER_PIC_SAILOR},
    {OBJ_EVENT_GFX_BUG_CATCHER,           TRAINER_PIC_BUG_CATCHER},
    // Costumes (8) - Default + region outfits + Team Rocket/Anime/Kanto Rival.
    // Team Magma costume deliberately excluded (Team Magma Grunt class above covers it).
    {OBJ_EVENT_GFX_BRENDAN_NORMAL,        TRAINER_PIC_BRENDAN},
    {OBJ_EVENT_GFX_GOLD_NORMAL,           TRAINER_PIC_JOHTO_M},
    {OBJ_EVENT_GFX_HOENN_NORMAL,          TRAINER_PIC_HOENN_M},
    {OBJ_EVENT_GFX_KANTO_M_NORMAL,        TRAINER_PIC_KANTO_M},
    {OBJ_EVENT_GFX_SINNOH_NORMAL,         TRAINER_PIC_SINNOH_M},
    {OBJ_EVENT_GFX_TEAM_ROCKET_M_NORMAL,  TRAINER_PIC_TEAM_ROCKET_M},
    {OBJ_EVENT_GFX_ANIME_M_NORMAL,        TRAINER_PIC_ANIME_M},
    {OBJ_EVENT_GFX_KANTO_RIVAL_M_NORMAL,  TRAINER_PIC_KANTO_RIVAL_M},
};

static const struct AsyncBattleSpritePair sAsyncBattleSpritePairs_Female[] =
{
    // Trainer classes (15)
    {OBJ_EVENT_GFX_AQUA_MEMBER_F,         TRAINER_PIC_AQUA_GRUNT_F},
    {OBJ_EVENT_GFX_COOLTRAINER_F,         TRAINER_PIC_COOLTRAINER_F},
    {OBJ_EVENT_GFX_MAGMA_MEMBER_F,        TRAINER_PIC_MAGMA_GRUNT_F},
    {OBJ_EVENT_GFX_EXPERT_F,              TRAINER_PIC_EXPERT_F},
    {OBJ_EVENT_GFX_HEX_MANIAC,            TRAINER_PIC_HEX_MANIAC},
    {OBJ_EVENT_GFX_REPORTER_F,            TRAINER_PIC_INTERVIEWER}, // no dedicated OW sprite, reuses Reporter
    {OBJ_EVENT_GFX_TUBER_F,               TRAINER_PIC_TUBER_F},
    {OBJ_EVENT_GFX_BEAUTY,                TRAINER_PIC_BEAUTY},
    {OBJ_EVENT_GFX_PICNICKER,             TRAINER_PIC_PICNICKER},
    {OBJ_EVENT_GFX_POKEFAN_F,             TRAINER_PIC_POKEFAN_F},
    {OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,  TRAINER_PIC_CYCLING_TRIATHLETE_F},
    {OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F,  TRAINER_PIC_RUNNING_TRIATHLETE_F},
    {OBJ_EVENT_GFX_SWIMMER_F,             TRAINER_PIC_SWIMMING_TRIATHLETE_F}, // no dedicated OW sprite, reuses Swimmer
    {OBJ_EVENT_GFX_SWIMMER_F,             TRAINER_PIC_SWIMMER_F},
    {OBJ_EVENT_GFX_LASS,                  TRAINER_PIC_LASS},
    // Costumes (6)
    {OBJ_EVENT_GFX_MAY_NORMAL,            TRAINER_PIC_MAY},
    {OBJ_EVENT_GFX_JOHTO_F_NORMAL,        TRAINER_PIC_JOHTO_F},
    {OBJ_EVENT_GFX_HOENN_F_NORMAL,        TRAINER_PIC_HOENN_F},
    {OBJ_EVENT_GFX_KANTO_F_NORMAL,        TRAINER_PIC_KANTO_F},
    {OBJ_EVENT_GFX_SINNOH_F_NORMAL,       TRAINER_PIC_SINNOH_F},
    {OBJ_EVENT_GFX_TEAM_ROCKET_F_NORMAL,  TRAINER_PIC_TEAM_ROCKET_F},
};
