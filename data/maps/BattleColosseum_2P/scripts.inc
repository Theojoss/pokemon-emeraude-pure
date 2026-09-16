BattleColosseum_2P_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleColosseum_2P_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleColosseum_2P_OnFrame
	.byte 0

// Both NPCs' visibility is decided here, before the map ever fades in/renders
// - not later via hideobjectat/addobject, which only toggle an object that's
// already spawned and would flash into view for a frame first. Real link
// battles (VAR_ASYNC_CODE_BATTLE_ARENA == 0): attendant visible, opponent
// hidden (revealed later by the vanilla link-room flow, not this cutscene).
// Async code battle (VAR_ASYNC_CODE_BATTLE_ARENA == 1): the reverse -
// opponent visible from the very first frame, attendant hidden.
BattleColosseum_2P_OnTransition:
	goto_if_eq VAR_ASYNC_CODE_BATTLE_ARENA, 1, BattleColosseum_2P_OnTransition_AsyncArrival
	setflag FLAG_HIDE_ASYNC_ARENA_OPPONENT
	clearflag FLAG_HIDE_LINK_ATTENDANT_FOR_ASYNC
	end
BattleColosseum_2P_OnTransition_AsyncArrival:
	clearflag FLAG_HIDE_ASYNC_ARENA_OPPONENT
	setflag FLAG_HIDE_LINK_ATTENDANT_FOR_ASYNC
	end

BattleColosseum_2P_OnFrame:
	map_script_2 VAR_ASYNC_CODE_BATTLE_ARENA, 1, BattleColosseum_2P_EventScript_AsyncArenaCutscene
	map_script_2 VAR_ASYNC_CODE_BATTLE_ARENA, 2, BattleColosseum_2P_EventScript_AsyncArenaExit
	.2byte 0

// Set (var to 1) and the opponent's overworld sprite resolved (special
// SetAsyncOpponentOverworldGfx) by CableClub_EventScript_EnterFriendCode
// right before warping the player in here - see data/scripts/cable_club.inc.
// Player always warps in at (6,8) (see the warp command in cable_club.inc) -
// BattleColosseum_2P_Movement_PlayerToSpot below assumes that exact start.
BattleColosseum_2P_EventScript_AsyncArenaCutscene::
	setvar VAR_ASYNC_CODE_BATTLE_ARENA, 0
	lockall
	applymovement LOCALID_PLAYER, BattleColosseum_2P_Movement_PlayerToSpot
	waitmovement 0
	msgbox BattleColosseum_2P_Text_AsyncOpponentIntro, MSGBOX_DEFAULT
	special StartAsyncCodeBattle
	waitstate
	releaseall
	end

// (6,8) -> (4,5): 2 steps north first (the entry corridor next to the warp
// tiles is only walkable going straight up - the room only opens up
// sideways further in, so going west immediately would walk off the
// accessible floor), then 2 west, 1 more north, facing the opponent at (9,5).
BattleColosseum_2P_Movement_PlayerToSpot:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	face_right
	step_end

// Set to 2 by CB2_EndTrainerBattle (src/battle_setup.c) once an async code
// battle ends, so the player automatically walks back out the way they came
// instead of being left to find the exit themselves. Walks the exact reverse
// of BattleColosseum_2P_Movement_PlayerToSpot, ending back on the (6,8) warp
// tile, then triggers the return warp explicitly instead of relying on
// stepping onto that tile to fire it - applymovement-driven steps don't
// trigger natural warp-tile detection the way real input-driven walking
// does, confirmed after landing right on (6,8) (and even one past it) did
// nothing. special CleanupLinkRoomState + special ReturnFromLinkRoom is the
// actual vanilla mechanism for leaving the link room (see
// EventScript_DoLinkRoomExit, data/scripts/cable_club.inc) - it uses the
// dynamic-warp destination special SetCableClubWarp recorded on the way in
// (cable_club.inc, right before the original warp in here) directly,
// without needing the player to physically step on anything, and - unlike
// DoCableClubWarp - doesn't block on real link traffic
// (Task_ReturnToWorldFromLinkRoom, src/field_screen_effect.c, only checks
// gReceivedRemoteLinkPlayers, which is naturally 0/FALSE here).
BattleColosseum_2P_EventScript_AsyncArenaExit::
	setvar VAR_ASYNC_CODE_BATTLE_ARENA, 0
	lockall
	applymovement LOCALID_PLAYER, BattleColosseum_2P_Movement_PlayerExitSpot
	waitmovement 0
	setvar VAR_0x8004, 0
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	end

// Reverse of BattleColosseum_2P_Movement_PlayerToSpot: (4,5) -> (6,8).
BattleColosseum_2P_Movement_PlayerExitSpot:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

// Never actually talked to - the whole cutscene is driven by
// BattleColosseum_2P_OnFrame above, not player interaction.
BattleColosseum_2P_EventScript_AsyncOpponentDummy::
	end

BattleColosseum_2P_Text_AsyncOpponentIntro:
	.string "Alors comme ça tu veux me\ndéfier {PLAYER} ?$"
