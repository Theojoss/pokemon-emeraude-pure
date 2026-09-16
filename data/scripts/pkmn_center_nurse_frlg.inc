EventScript_AfterWhiteOutHeal_Frlg::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_unset FLAG_NUZLOCKE, EventScript_AfterWhiteOutHeal_Frlg_Normal
	specialvar VAR_RESULT, NuzlockeHasAnyLivingPokemon
	goto_if_eq VAR_RESULT, FALSE, EventScript_AfterWhiteOutHeal_Frlg_ForcedDisable
	msgbox gText_NuzlockeWhiteOut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EventScript_AfterWhiteOutHeal_Frlg_DisableNuzlocke
	goto EventScript_AfterWhiteOutHeal_Frlg_ContinueNuzlocke

EventScript_AfterWhiteOutHeal_Frlg_ForcedDisable::
	clearflag FLAG_NUZLOCKE
	message gText_NuzlockeNoMonsLeft
	waitmessage
	delay 90
	msgbox gText_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreFirstBoss
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	message gText_DataWillBeSaved
	waitmessage
	special NuzlockeSilentSave
	message gText_SaveCompleted
	waitmessage
	delay 90
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHeal_Frlg_DisableNuzlocke::
	clearflag FLAG_NUZLOCKE
	message gText_NuzlockeDisabled
	waitmessage
	delay 90
	msgbox gText_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreFirstBoss
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	message gText_DataWillBeSaved
	waitmessage
	special NuzlockeSilentSave
	message gText_SaveCompleted
	waitmessage
	delay 90
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHeal_Frlg_ContinueNuzlocke::
	msgbox gText_ContinueNuzlockeMode, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHeal_Frlg_Normal::
	msgbox gText_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	call_if_unset FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsgPreFirstBoss
	call_if_set FLAG_DEFEATED_BROCK, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_PkmnCenterNurse_Frlg::
	message Text_WelcomeWantToHealPkmn_Frlg
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn_Frlg
	case 1 EventScript_PkmnCenterNurse_Goodbye_Frlg
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye_Frlg
	end

EventScript_PkmnCenterNurse_HealPkmn_Frlg::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSeconds_Frlg
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg
	goto EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom_Frlg
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn_Frlg::
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	return

EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom_Frlg::
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Frlg
	end

EventScript_PkmnCenterNurse_ReturnPkmn_Frlg::
	message Text_RestoredPkmnToFullHealth_Frlg
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom_Frlg::
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, EventScript_PkmnCenterNurse_ReturnPkmn_Frlg
	msgbox Text_RestoredPkmnToFullHealth_Frlg
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message Text_PlayerIsPlayingRightNowGoForIt_Frlg
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

EventScript_PkmnCenterNurse_Goodbye_Frlg::
	msgbox Text_WeHopeToSeeYouAgain_Frlg
	return

Movement_Bow::
	nurse_joy_bow
	delay_4
	step_end

Text_WelcomeWantToHealPkmn_Frlg::
	.string "Bienvenue dans notre CENTRE\n"
	.string "POKéMON!\p"
	.string "Voulez-vous que je m'occupe\n"
	.string "de vos POKéMON?$"

Text_TakeYourPkmnForFewSeconds_Frlg::
	.string "OK, je prends vos POKéMON un\n"
	.string "instant.$"

Text_WeHopeToSeeYouAgain_Frlg::
	.string "A bientôt!$"

Text_RestoredPkmnToFullHealth_Frlg::
	.string "Merci d'avoir attendu.\p"
	.string "Vos POKéMON sont en super forme.$"
