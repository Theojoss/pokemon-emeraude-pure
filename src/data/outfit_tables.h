#include "constants/event_objects.h"

// outfits (costume system)

static const u8 sRegionMapIconGfx_JohtoM[] = INCGFX_U8("graphics/pokenav/region_map/johto_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_JohtoM[] = INCGFX_U16("graphics/pokenav/region_map/johto_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_JohtoF[] = INCGFX_U8("graphics/pokenav/region_map/johto_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_JohtoF[] = INCGFX_U16("graphics/pokenav/region_map/johto_f_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_HoennM[] = INCGFX_U8("graphics/pokenav/region_map/hoenn_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_HoennM[] = INCGFX_U16("graphics/pokenav/region_map/hoenn_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_HoennF[] = INCGFX_U8("graphics/pokenav/region_map/hoenn_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_HoennF[] = INCGFX_U16("graphics/pokenav/region_map/hoenn_f_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_KantoM[] = INCGFX_U8("graphics/pokenav/region_map/kanto_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_KantoM[] = INCGFX_U16("graphics/pokenav/region_map/kanto_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_KantoF[] = INCGFX_U8("graphics/pokenav/region_map/kanto_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_KantoF[] = INCGFX_U16("graphics/pokenav/region_map/kanto_f_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_SinnohM[] = INCGFX_U8("graphics/pokenav/region_map/sinnoh_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_SinnohM[] = INCGFX_U16("graphics/pokenav/region_map/sinnoh_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_SinnohF[] = INCGFX_U8("graphics/pokenav/region_map/sinnoh_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_SinnohF[] = INCGFX_U16("graphics/pokenav/region_map/sinnoh_f_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_TeamRocketM[] = INCGFX_U8("graphics/pokenav/region_map/team_rocket_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_TeamRocketM[] = INCGFX_U16("graphics/pokenav/region_map/team_rocket_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_TeamRocketF[] = INCGFX_U8("graphics/pokenav/region_map/team_rocket_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_TeamRocketF[] = INCGFX_U16("graphics/pokenav/region_map/team_rocket_f_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_AnimeM[] = INCGFX_U8("graphics/pokenav/region_map/anime_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_AnimeM[] = INCGFX_U16("graphics/pokenav/region_map/anime_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_TeamMagmaM[] = INCGFX_U8("graphics/pokenav/region_map/team_magma_m_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_TeamMagmaM[] = INCGFX_U16("graphics/pokenav/region_map/team_magma_m_icon.png", ".gbapal");
static const u8 sRegionMapIconGfx_TeamMagmaF[] = INCGFX_U8("graphics/pokenav/region_map/team_magma_f_icon.png", ".4bpp");
static const u16 sRegionMapIconPal_TeamMagmaF[] = INCGFX_U16("graphics/pokenav/region_map/team_magma_f_icon.png", ".gbapal");

const struct Outfit gOutfits[OUTFIT_COUNT] =
{
    [OUTFIT_NONE] = {
        .isHidden = TRUE
    },
    [OUTFIT_DEFAULT] = {
        .isHidden = FALSE,
        .prices = { 0, 0 },
        .name = COMPOUND_STRING("DEFAULT"),
        .desc = COMPOUND_STRING("La tenue avec laquelle tu as\ncommencé ton aventure."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_BRENDAN,
            [FEMALE] = TRAINER_PIC_MAY,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = PLAYER_AVATAR_GFX_MALE_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = PLAYER_AVATAR_GFX_MALE_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PLAYER_AVATAR_GFX_MALE_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = PLAYER_AVATAR_GFX_MALE_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_MALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = PLAYER_AVATAR_GFX_MALE_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = PLAYER_AVATAR_GFX_MALE_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_MALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = PLAYER_AVATAR_GFX_MALE_VSSEEKER,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = PLAYER_AVATAR_GFX_FEMALE_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = PLAYER_AVATAR_GFX_FEMALE_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_FEMALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = PLAYER_AVATAR_GFX_FEMALE_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = PLAYER_AVATAR_GFX_FEMALE_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_FEMALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = PLAYER_AVATAR_GFX_FEMALE_VSSEEKER,
            },
        },
    },
    [OUTFIT_GOLD] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("JOHTO"),
        .desc = COMPOUND_STRING(
            "Une tenue inspirée d'une région\n"
            "imprégnée par la tradition."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_JOHTO_M,
            [FEMALE] = TRAINER_PIC_JOHTO_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_JohtoM,
            [FEMALE] = sRegionMapIconGfx_JohtoF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_JohtoM,
            [FEMALE] = sRegionMapIconPal_JohtoF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_GOLD_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_GOLD_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_GOLD_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_GOLD_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_GOLD_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_GOLD_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_GOLD_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_GOLD_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_GOLD_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_JOHTO_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_JOHTO_F_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_JOHTO_F_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_JOHTO_F_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_JOHTO_F_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_JOHTO_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_JOHTO_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_JOHTO_F_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_JOHTO_F_FIELD_MOVE,
            },
        },
    },
    [OUTFIT_HOENN] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("HOENN"),
        .desc = COMPOUND_STRING(
            "Une tenue inspirée d'une région\n"
            "au climat chaud."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_HOENN_M,
            [FEMALE] = TRAINER_PIC_HOENN_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_HoennM,
            [FEMALE] = sRegionMapIconGfx_HoennF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_HoennM,
            [FEMALE] = sRegionMapIconPal_HoennF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_HOENN_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_HOENN_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_HOENN_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_HOENN_SURFING,
                // No dedicated underwater sprite, fall back to the default look.
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_MALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_HOENN_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_HOENN_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_HOENN_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_HOENN_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_HOENN_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_HOENN_F_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_HOENN_F_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_HOENN_F_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_HOENN_F_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_HOENN_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_HOENN_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_HOENN_F_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_HOENN_F_FIELD_MOVE,
            },
        },
    },
    [OUTFIT_KANTO] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("KANTO"),
        .desc = COMPOUND_STRING(
            "Une tenue inspirée d'une\n"
            "région iconique."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_KANTO_M,
            [FEMALE] = TRAINER_PIC_KANTO_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_KantoM,
            [FEMALE] = sRegionMapIconGfx_KantoF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_KantoM,
            [FEMALE] = sRegionMapIconPal_KantoF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_KANTO_M_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_KANTO_M_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_KANTO_M_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_KANTO_M_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_KANTO_M_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_KANTO_M_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_KANTO_M_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_KANTO_M_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_KANTO_M_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_KANTO_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_KANTO_F_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_KANTO_F_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_KANTO_F_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_KANTO_F_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_KANTO_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_KANTO_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_KANTO_F_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_KANTO_F_FIELD_MOVE,
            },
        },
    },
    [OUTFIT_SINNOH] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("SINNOH"),
        .desc = COMPOUND_STRING(
            "Une tenue inspirée d'une région\n"
            "au climat froid."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_SINNOH_M,
            [FEMALE] = TRAINER_PIC_SINNOH_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_SinnohM,
            [FEMALE] = sRegionMapIconGfx_SinnohF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_SinnohM,
            [FEMALE] = sRegionMapIconPal_SinnohF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_SINNOH_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_SINNOH_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_SINNOH_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_SINNOH_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_SINNOH_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_SINNOH_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_SINNOH_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_SINNOH_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_SINNOH_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_SINNOH_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_SINNOH_F_MACH_BIKE,
                // No dedicated acro bike sprite, fall back to the default look.
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_SINNOH_F_SURFING,
                // No dedicated underwater sprite, fall back to the default look.
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_FEMALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_SINNOH_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_SINNOH_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_SINNOH_F_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_SINNOH_F_FIELD_MOVE,
            },
        },
    },
    // WIP: underwater/watering sprites not provided yet for either outfit, so those
    // states fall back to the default look. The female acro bike sheet's last 18
    // frames are also a placeholder (see notes given to the user) until redrawn.
    [OUTFIT_TEAM_ROCKET] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("TEAM ROCKET"),
        .desc = COMPOUND_STRING(
            "La tenue d'une organisation à la\n"
            "fois maléfique et emblématique."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_TEAM_ROCKET_M,
            [FEMALE] = TRAINER_PIC_TEAM_ROCKET_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_TeamRocketM,
            [FEMALE] = sRegionMapIconGfx_TeamRocketF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_TeamRocketM,
            [FEMALE] = sRegionMapIconPal_TeamRocketF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_TEAM_ROCKET_M_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_TEAM_ROCKET_M_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_TEAM_ROCKET_M_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_TEAM_ROCKET_M_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_MALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_TEAM_ROCKET_M_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_TEAM_ROCKET_M_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_MALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_TEAM_ROCKET_M_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_TEAM_ROCKET_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_TEAM_ROCKET_F_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_TEAM_ROCKET_F_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_TEAM_ROCKET_F_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_FEMALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_TEAM_ROCKET_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_TEAM_ROCKET_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_FEMALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_TEAM_ROCKET_F_FIELD_MOVE,
            },
        },
    },
    [OUTFIT_ANIME] = {
        .isHidden = FALSE,
        .maleOnly = TRUE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("ANIME"),
        .desc = COMPOUND_STRING(
            "La tenue du plus grand\n"
            "dresseur de tous les temps."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_ANIME_M,
            [FEMALE] = TRAINER_PIC_MAY,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_AnimeM,
            [FEMALE] = NULL,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_AnimeM,
            [FEMALE] = NULL,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_ANIME_M_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_ANIME_M_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_ANIME_M_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_ANIME_M_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_ANIME_M_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_ANIME_M_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_ANIME_M_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_MALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_ANIME_M_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = PLAYER_AVATAR_GFX_FEMALE_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = PLAYER_AVATAR_GFX_FEMALE_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = PLAYER_AVATAR_GFX_FEMALE_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = PLAYER_AVATAR_GFX_FEMALE_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = PLAYER_AVATAR_GFX_FEMALE_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = PLAYER_AVATAR_GFX_FEMALE_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = PLAYER_AVATAR_GFX_FEMALE_VSSEEKER,
            },
        },
    },
    [OUTFIT_TEAM_MAGMA] = {
        .isHidden = FALSE,
        .prices = { 5000, 5000 },
        .name = COMPOUND_STRING("TEAM MAGMA"),
        .desc = COMPOUND_STRING(
            "La tenue d'une organisation\n"
            "cherchant à étendre les terres\n"
            "émergées."),
        .trainerPics = {
            [MALE]   = TRAINER_PIC_TEAM_MAGMA_M,
            [FEMALE] = TRAINER_PIC_TEAM_MAGMA_F,
        },
        .regionMapIconGfx = {
            [MALE]   = sRegionMapIconGfx_TeamMagmaM,
            [FEMALE] = sRegionMapIconGfx_TeamMagmaF,
        },
        .regionMapIconPal = {
            [MALE]   = sRegionMapIconPal_TeamMagmaM,
            [FEMALE] = sRegionMapIconPal_TeamMagmaF,
        },
        .avatarGfxIds = {
            [MALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_TEAM_MAGMA_M_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_TEAM_MAGMA_M_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_TEAM_MAGMA_M_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_TEAM_MAGMA_M_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_TEAM_MAGMA_M_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_TEAM_MAGMA_M_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_TEAM_MAGMA_M_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_TEAM_MAGMA_M_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_TEAM_MAGMA_M_FIELD_MOVE,
            },
            [FEMALE] = {
                [PLAYER_AVATAR_STATE_NORMAL]     = OBJ_EVENT_GFX_TEAM_MAGMA_F_NORMAL,
                [PLAYER_AVATAR_STATE_MACH_BIKE]  = OBJ_EVENT_GFX_TEAM_MAGMA_F_MACH_BIKE,
                [PLAYER_AVATAR_STATE_ACRO_BIKE]  = OBJ_EVENT_GFX_TEAM_MAGMA_F_ACRO_BIKE,
                [PLAYER_AVATAR_STATE_SURFING]    = OBJ_EVENT_GFX_TEAM_MAGMA_F_SURFING,
                [PLAYER_AVATAR_STATE_UNDERWATER] = OBJ_EVENT_GFX_TEAM_MAGMA_F_UNDERWATER,
                [PLAYER_AVATAR_STATE_FIELD_MOVE] = OBJ_EVENT_GFX_TEAM_MAGMA_F_FIELD_MOVE,
                [PLAYER_AVATAR_STATE_FISHING]    = OBJ_EVENT_GFX_TEAM_MAGMA_F_FISHING,
                [PLAYER_AVATAR_STATE_WATERING]   = OBJ_EVENT_GFX_TEAM_MAGMA_F_WATERING,
                [PLAYER_AVATAR_STATE_VSSEEKER]   = OBJ_EVENT_GFX_TEAM_MAGMA_F_FIELD_MOVE,
            },
        },
    },
};
