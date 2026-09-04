RecifDesLegendes_Indoor_MapScripts::
	.byte 0

RecifDesLegendes_Indoor_EventScript_Geeta::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Geeta, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Leon::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Leon, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Diantha::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Diantha, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Iris::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Iris, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Cynthia::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Cynthia, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Steven::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Steven, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Lance::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Lance, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_Blue::
	lock
	faceplayer
	msgbox RecifDesLegendes_Indoor_Text_Blue, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_Text_Geeta:
	.string "Bonjour. Je suis ALISMA,\n"
	.string "Championne de la Ligue de Paldea.\p"
	.string "Je supervise habituellement les\n"
	.string "épreuves des jeunes dresseurs, mais\l"
	.string "ce tournoi m'a semblé... intéressant.\p"
	.string "J'espère que tu sauras te montrer à\n"
	.string "la hauteur.$"

RecifDesLegendes_Indoor_Text_Leon:
	.string "Yaahoo! Moi c'est TARAK,\n"
	.string "Champion de Galar!\p"
	.string "Ah, ce tournoi promet d'être\n"
	.string "ÉNORME! J'ai hâte de voir des combats\l"
	.string "dignes d'une finale de Coupe!\p"
	.string "Donne tout ce que tu as,\n"
	.string "{PLAYER}{KUN}!$"

RecifDesLegendes_Indoor_Text_Diantha:
	.string "Enchantée, je m'appelle\n"
	.string "DIANTHEA, Championne de la Ligue\l"
	.string "de Kalos.\p"
	.string "Entre deux tournages, il m'arrive de\n"
	.string "fouler à nouveau les terrains de\l"
	.string "combat... et ce tournoi est une\l"
	.string "occasion en or.\p"
	.string "J'espère t'offrir un combat aussi\n"
	.string "beau qu'un film.$"

RecifDesLegendes_Indoor_Text_Iris:
	.string "Salut! Moi c'est IRIS,\n"
	.string "Championne d'Unys!\p"
	.string "J'adore les Pokémon Dragon, tu sais?\n"
	.string "Un jour tu comprendras ce que ça\l"
	.string "fait de voir le monde comme un vrai\l"
	.string "dresseur!\p"
	.string "J'ai hâte de voir de quoi tu es\n"
	.string "capable ici!$"

RecifDesLegendes_Indoor_Text_Cynthia:
	.string "Bonjour. Je m'appelle\n"
	.string "CYNTHIA, je suis la Championne de\l"
	.string "la Ligue de Sinnoh.\p"
	.string "Les légendes de ce récif m'intriguent...\n"
	.string "il y a toujours quelque chose à\l"
	.string "apprendre des liens entre Pokémon et\l"
	.string "dresseurs.\p"
	.string "J'espère que ce tournoi nous en\n"
	.string "apprendra beaucoup, à toi comme à moi.$"

RecifDesLegendes_Indoor_Text_Steven:
	.string "Te voilà! Je suis ravi que tu\n"
	.string "aies accepté ma proposition de venir\l"
	.string "participer à ce tournoi.\p"
	.string "Regarde autour de toi... Les plus\n"
	.string "grands Champions, réunis en un seul\l"
	.string "lieu. Ce n'est pas rien.\p"
	.string "J'ai hâte de voir jusqu'où tu peux\n"
	.string "aller, {PLAYER}{KUN}.$"

RecifDesLegendes_Indoor_Text_Lance:
	.string "...Je suis PETER, Maître de\n"
	.string "la Ligue Pokémon et dresseur de\l"
	.string "Dracolosse.\p"
	.string "Un tournoi rassemblant des Champions\n"
	.string "de toutes les régions... Voilà qui va\l"
	.string "enfin me permettre de mesurer ma\l"
	.string "force face à de vrais rivaux.\p"
	.string "Ne me déçois pas.$"

RecifDesLegendes_Indoor_Text_Blue:
	.string "Alors c'est toi, {PLAYER}{KUN}?\n"
	.string "J'ai entendu parler de toi.\p"
	.string "Moi c'est BLUE, l'ancien Champion de\n"
	.string "Kanto. Enfin... le meilleur, tout\l"
	.string "simplement.\p"
	.string "Ce tournoi va être l'occasion\n"
	.string "parfaite de prouver une fois de plus\l"
	.string "qui est le plus fort.$"

RecifDesLegendes_Indoor_EventScript_Presentateur::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_RECIF_PLAYED_TODAY, RecifDesLegendes_Indoor_EventScript_PresenterAlreadyPlayedToday
	msgbox RecifDesLegendes_Indoor_Text_PresenterWelcome, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, RecifDesLegendes_Indoor_EventScript_PresenterDecline
	case MULTI_B_PRESSED, RecifDesLegendes_Indoor_EventScript_PresenterDecline
	case YES, RecifDesLegendes_Indoor_EventScript_PresenterAccept
	end

RecifDesLegendes_Indoor_EventScript_PresenterAlreadyPlayedToday::
	msgbox RecifDesLegendes_Indoor_Text_PresenterAlreadyPlayedToday, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_PresenterDecline::
	msgbox RecifDesLegendes_Indoor_Text_PresenterComeBackLater, MSGBOX_DEFAULT
	release
	end

RecifDesLegendes_Indoor_EventScript_PresenterAccept::
	msgbox RecifDesLegendes_Indoor_Text_PresenterTakeYourPlace, MSGBOX_DEFAULT
	closemessage
	setvar VAR_RECIF_ROUND, 1
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_NORTH, RecifDesLegendes_Indoor_EventScript_PlayerFromSouth
	case DIR_SOUTH, RecifDesLegendes_Indoor_EventScript_PlayerFromNorth
	case DIR_EAST, RecifDesLegendes_Indoor_EventScript_PlayerFromWest
	case DIR_WEST, RecifDesLegendes_Indoor_EventScript_PlayerFromEast
	end

RecifDesLegendes_Indoor_EventScript_PlayerFromSouth::
	applymovement LOCALID_PLAYER, RecifDesLegendes_Indoor_Movement_PlayerFromSouthToArena
	waitmovement LOCALID_PLAYER
	goto RecifDesLegendes_Indoor_EventScript_DrawNextOpponent

RecifDesLegendes_Indoor_EventScript_PlayerFromNorth::
	applymovement LOCALID_PLAYER, RecifDesLegendes_Indoor_Movement_PlayerFromNorthToArena
	waitmovement LOCALID_PLAYER
	goto RecifDesLegendes_Indoor_EventScript_DrawNextOpponent

RecifDesLegendes_Indoor_EventScript_PlayerFromWest::
	applymovement LOCALID_PLAYER, RecifDesLegendes_Indoor_Movement_PlayerFromWestToArena
	waitmovement LOCALID_PLAYER
	goto RecifDesLegendes_Indoor_EventScript_DrawNextOpponent

RecifDesLegendes_Indoor_EventScript_PlayerFromEast::
	applymovement LOCALID_PLAYER, RecifDesLegendes_Indoor_Movement_PlayerFromEastToArena
	waitmovement LOCALID_PLAYER

RecifDesLegendes_Indoor_EventScript_DrawNextOpponent::
	random 7
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_TEMP_1
	case 0, RecifDesLegendes_Indoor_EventScript_CheckGeeta
	case 1, RecifDesLegendes_Indoor_EventScript_CheckLeon
	case 2, RecifDesLegendes_Indoor_EventScript_CheckDiantha
	case 3, RecifDesLegendes_Indoor_EventScript_CheckIris
	case 4, RecifDesLegendes_Indoor_EventScript_CheckCynthia
	case 5, RecifDesLegendes_Indoor_EventScript_CheckLance
	case 6, RecifDesLegendes_Indoor_EventScript_CheckBlue
	end

RecifDesLegendes_Indoor_EventScript_CheckGeeta::
	goto_if_set FLAG_RECIF_FACED_GEETA, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawGeeta

RecifDesLegendes_Indoor_EventScript_CheckLeon::
	goto_if_set FLAG_RECIF_FACED_LEON, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawLeon

RecifDesLegendes_Indoor_EventScript_CheckDiantha::
	goto_if_set FLAG_RECIF_FACED_DIANTHA, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawDiantha

RecifDesLegendes_Indoor_EventScript_CheckIris::
	goto_if_set FLAG_RECIF_FACED_IRIS, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawIris

RecifDesLegendes_Indoor_EventScript_CheckCynthia::
	goto_if_set FLAG_RECIF_FACED_CYNTHIA, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawCynthia

RecifDesLegendes_Indoor_EventScript_CheckLance::
	goto_if_set FLAG_RECIF_FACED_LANCE, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawLance

RecifDesLegendes_Indoor_EventScript_CheckBlue::
	goto_if_set FLAG_RECIF_FACED_BLUE, RecifDesLegendes_Indoor_EventScript_DrawNextOpponent
	goto RecifDesLegendes_Indoor_EventScript_DrawBlue

RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome::
	special HealPlayerParty
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RecifDesLegendes_Indoor_EventScript_PlayerWonRound
	goto RecifDesLegendes_Indoor_EventScript_PlayerLostRound

RecifDesLegendes_Indoor_EventScript_PlayerLostRound::
	setflag FLAG_RECIF_PLAYED_TODAY
	clearflag FLAG_RECIF_FACED_GEETA
	clearflag FLAG_RECIF_FACED_LEON
	clearflag FLAG_RECIF_FACED_DIANTHA
	clearflag FLAG_RECIF_FACED_IRIS
	clearflag FLAG_RECIF_FACED_CYNTHIA
	clearflag FLAG_RECIF_FACED_LANCE
	clearflag FLAG_RECIF_FACED_BLUE
	msgbox RecifDesLegendes_Indoor_Text_PresenterAfterLoss, MSGBOX_DEFAULT
	releaseall
	end

RecifDesLegendes_Indoor_EventScript_PlayerWonRound::
	goto_if_eq VAR_RECIF_ROUND, 4, RecifDesLegendes_Indoor_EventScript_TournamentWon
	msgbox RecifDesLegendes_Indoor_Text_PresenterAnnounceWinner, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
	addvar VAR_RECIF_ROUND, 1
	goto RecifDesLegendes_Indoor_EventScript_DrawNextOpponent

RecifDesLegendes_Indoor_EventScript_TournamentWon::
	playse SE_M_ENCORE2
	waitse
	playbgm MUS_VICTORY_LEAGUE, FALSE
	msgbox RecifDesLegendes_Indoor_Text_PresenterTournamentChampion, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, RecifDesLegendes_Indoor_EventScript_CheckGiveAnimeOutfit
	setflag FLAG_RECIF_PLAYED_TODAY
	clearflag FLAG_RECIF_FACED_GEETA
	clearflag FLAG_RECIF_FACED_LEON
	clearflag FLAG_RECIF_FACED_DIANTHA
	clearflag FLAG_RECIF_FACED_IRIS
	clearflag FLAG_RECIF_FACED_CYNTHIA
	clearflag FLAG_RECIF_FACED_LANCE
	clearflag FLAG_RECIF_FACED_BLUE
	releaseall
	end

RecifDesLegendes_Indoor_EventScript_CheckGiveAnimeOutfit::
	call_if_outfitlocked OUTFIT_ANIME, RecifDesLegendes_Indoor_EventScript_GiveAnimeOutfit
	return

RecifDesLegendes_Indoor_EventScript_GiveAnimeOutfit::
	setvar VAR_0x8004, OUTFIT_ANIME
	call Common_EventScript_ObtainedOutfit
	return

RecifDesLegendes_Indoor_EventScript_AnnounceRoundName::
	switch VAR_RECIF_ROUND
	case 2, RecifDesLegendes_Indoor_EventScript_AnnounceQuarterfinal
	case 3, RecifDesLegendes_Indoor_EventScript_AnnounceSemifinal
	case 4, RecifDesLegendes_Indoor_EventScript_AnnounceFinal
	end

RecifDesLegendes_Indoor_EventScript_AnnounceQuarterfinal::
	msgbox RecifDesLegendes_Indoor_Text_RoundQuarterfinal, MSGBOX_DEFAULT
	closemessage
	return

RecifDesLegendes_Indoor_EventScript_AnnounceSemifinal::
	msgbox RecifDesLegendes_Indoor_Text_RoundSemifinal, MSGBOX_DEFAULT
	closemessage
	return

RecifDesLegendes_Indoor_EventScript_AnnounceFinal::
	msgbox RecifDesLegendes_Indoor_Text_RoundFinalHype1, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
	msgbox RecifDesLegendes_Indoor_Text_RoundFinalHype2, MSGBOX_DEFAULT
	closemessage
	return

RecifDesLegendes_Indoor_EventScript_DrawGeeta::
	setflag FLAG_RECIF_FACED_GEETA
	removeobject LOCALID_RECIF_GEETA
	delay 1
	addobject LOCALID_RECIF_GEETA
	applymovement LOCALID_RECIF_GEETA, RecifDesLegendes_Indoor_Movement_GeetaToArena
	waitmovement LOCALID_RECIF_GEETA
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceGeeta
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceGeeta::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Geeta
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceGeeta, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceGeeta
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Geeta::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceGeeta, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceGeeta::
	closemessage
	cleartrainerflag TRAINER_GEETA
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_GEETA, RecifDesLegendes_Indoor_Text_GeetaBattleIntro, RecifDesLegendes_Indoor_Text_GeetaBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleGeeta, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleGeeta::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_GEETA, RecifDesLegendes_Indoor_Movement_GeetaToSeat
	waitmovement LOCALID_RECIF_GEETA
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawLeon::
	setflag FLAG_RECIF_FACED_LEON
	removeobject LOCALID_RECIF_LEON
	delay 1
	addobject LOCALID_RECIF_LEON
	applymovement LOCALID_RECIF_LEON, RecifDesLegendes_Indoor_Movement_LeonToArena
	waitmovement LOCALID_RECIF_LEON
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceLeon
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceLeon::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Leon
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceLeon, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceLeon
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Leon::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceLeon, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceLeon::
	closemessage
	cleartrainerflag TRAINER_LEON
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_LEON, RecifDesLegendes_Indoor_Text_LeonBattleIntro, RecifDesLegendes_Indoor_Text_LeonBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleLeon, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleLeon::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_LEON, RecifDesLegendes_Indoor_Movement_LeonToSeat
	waitmovement LOCALID_RECIF_LEON
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawDiantha::
	setflag FLAG_RECIF_FACED_DIANTHA
	removeobject LOCALID_RECIF_DIANTHA
	delay 1
	addobject LOCALID_RECIF_DIANTHA
	applymovement LOCALID_RECIF_DIANTHA, RecifDesLegendes_Indoor_Movement_DianthaToArena
	waitmovement LOCALID_RECIF_DIANTHA
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceDiantha
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceDiantha::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Diantha
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceDiantha, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceDiantha
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Diantha::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceDiantha, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceDiantha::
	closemessage
	cleartrainerflag TRAINER_DIANTHA
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_DIANTHA, RecifDesLegendes_Indoor_Text_DianthaBattleIntro, RecifDesLegendes_Indoor_Text_DianthaBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleDiantha, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleDiantha::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_DIANTHA, RecifDesLegendes_Indoor_Movement_DianthaToSeat
	waitmovement LOCALID_RECIF_DIANTHA
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawIris::
	setflag FLAG_RECIF_FACED_IRIS
	removeobject LOCALID_RECIF_IRIS
	delay 1
	addobject LOCALID_RECIF_IRIS
	applymovement LOCALID_RECIF_IRIS, RecifDesLegendes_Indoor_Movement_IrisToArena
	waitmovement LOCALID_RECIF_IRIS
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceIris
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceIris::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Iris
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceIris, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceIris
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Iris::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceIris, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceIris::
	closemessage
	cleartrainerflag TRAINER_IRIS
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_IRIS, RecifDesLegendes_Indoor_Text_IrisBattleIntro, RecifDesLegendes_Indoor_Text_IrisBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleIris, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleIris::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_IRIS, RecifDesLegendes_Indoor_Movement_IrisToSeat
	waitmovement LOCALID_RECIF_IRIS
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawCynthia::
	setflag FLAG_RECIF_FACED_CYNTHIA
	removeobject LOCALID_RECIF_CYNTHIA
	delay 1
	addobject LOCALID_RECIF_CYNTHIA
	applymovement LOCALID_RECIF_CYNTHIA, RecifDesLegendes_Indoor_Movement_CynthiaToArena
	waitmovement LOCALID_RECIF_CYNTHIA
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceCynthia
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceCynthia::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Cynthia
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceCynthia, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceCynthia
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Cynthia::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceCynthia, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceCynthia::
	closemessage
	cleartrainerflag TRAINER_CYNTHIA
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_CYNTHIA, RecifDesLegendes_Indoor_Text_CynthiaBattleIntro, RecifDesLegendes_Indoor_Text_CynthiaBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleCynthia, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleCynthia::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_CYNTHIA, RecifDesLegendes_Indoor_Movement_CynthiaToSeat
	waitmovement LOCALID_RECIF_CYNTHIA
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawLance::
	setflag FLAG_RECIF_FACED_LANCE
	removeobject LOCALID_RECIF_LANCE
	delay 1
	addobject LOCALID_RECIF_LANCE
	applymovement LOCALID_RECIF_LANCE, RecifDesLegendes_Indoor_Movement_LanceToArena
	waitmovement LOCALID_RECIF_LANCE
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceLance
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceLance::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Lance
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceLance, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceLance
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Lance::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceLance, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceLance::
	closemessage
	cleartrainerflag TRAINER_LANCE
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_LANCE, RecifDesLegendes_Indoor_Text_LanceBattleIntro, RecifDesLegendes_Indoor_Text_LanceBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleLance, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleLance::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_LANCE, RecifDesLegendes_Indoor_Movement_LanceToSeat
	waitmovement LOCALID_RECIF_LANCE
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome

RecifDesLegendes_Indoor_EventScript_DrawBlue::
	setflag FLAG_RECIF_FACED_BLUE
	removeobject LOCALID_RECIF_BLUE
	delay 1
	addobject LOCALID_RECIF_BLUE
	applymovement LOCALID_RECIF_BLUE, RecifDesLegendes_Indoor_Movement_BlueToArena
	waitmovement LOCALID_RECIF_BLUE
	waitmovement LOCALID_PLAYER
	goto_if_ne VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceBlue
	msgbox RecifDesLegendes_Indoor_Text_PresenterHype, MSGBOX_DEFAULT
	closemessage
	playse SE_M_ENCORE2
	waitse
RecifDesLegendes_Indoor_EventScript_IntroduceBlue::
	goto_if_eq VAR_RECIF_ROUND, 1, RecifDesLegendes_Indoor_EventScript_IntroduceRound1Blue
	call RecifDesLegendes_Indoor_EventScript_AnnounceRoundName
	msgbox RecifDesLegendes_Indoor_Text_PresenterFaceBlue, MSGBOX_DEFAULT
	goto RecifDesLegendes_Indoor_EventScript_FinishIntroduceBlue
RecifDesLegendes_Indoor_EventScript_IntroduceRound1Blue::
	msgbox RecifDesLegendes_Indoor_Text_PresenterIntroduceBlue, MSGBOX_DEFAULT
RecifDesLegendes_Indoor_EventScript_FinishIntroduceBlue::
	closemessage
	cleartrainerflag TRAINER_BLUE
	setflag FLAG_RECIF_NO_WHITEOUT
	trainerbattle_single TRAINER_BLUE, RecifDesLegendes_Indoor_Text_BlueBattleIntro, RecifDesLegendes_Indoor_Text_BlueBattleDefeat, RecifDesLegendes_Indoor_EventScript_AfterBattleBlue, FALSE
	end

RecifDesLegendes_Indoor_EventScript_AfterBattleBlue::
	clearflag FLAG_RECIF_NO_WHITEOUT
	applymovement LOCALID_RECIF_BLUE, RecifDesLegendes_Indoor_Movement_BlueToSeat
	waitmovement LOCALID_RECIF_BLUE
	goto RecifDesLegendes_Indoor_EventScript_ResolveBattleOutcome


@ Row 7 runs fully clear from column 0 to 19. Column 3 (west) and column 16 (east)
@ are the only fully-clear vertical corridors connecting it to rows 5/9/11 - the rows
@ in between have chairs blocking columns 4/6/13/15, and row 9 is walled off from
@ column 7 to 12 (the screen's base). Every path below funnels through those two
@ corridors and always crosses the (4,7)/(13,7) checkpoints on row 7.

RecifDesLegendes_Indoor_Movement_PlayerFromSouthToArena:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_PlayerFromNorthToArena:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_PlayerFromWestToArena:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_PlayerFromEastToArena:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_GeetaToArena:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_GeetaToSeat:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_LeonToArena:
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_LeonToSeat:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_DianthaToArena:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_DianthaToSeat:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_IrisToArena:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_IrisToSeat:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_CynthiaToArena:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_CynthiaToSeat:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_LanceToArena:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_LanceToSeat:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	face_right
	step_end

RecifDesLegendes_Indoor_Movement_BlueToArena:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	face_left
	step_end

RecifDesLegendes_Indoor_Movement_BlueToSeat:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end


RecifDesLegendes_Indoor_Text_PresenterWelcome:
	.string "Bienvenue au RECIF DES LEGENDES!\p"
	.string "Veux-tu participer au tournoi?$"

RecifDesLegendes_Indoor_Text_PresenterComeBackLater:
	.string "Très bien. Reviens quand tu seras\n"
	.string "prêt.$"

RecifDesLegendes_Indoor_Text_PresenterTakeYourPlace:
	.string "Parfait! Alors... prends place!$"

RecifDesLegendes_Indoor_Text_PresenterAlreadyPlayedToday:
	.string "Tu devras attendre demain pour\n"
	.string "retenter ta chance.$"

RecifDesLegendes_Indoor_Text_PresenterAfterLoss:
	.string "Ah... Dommage!\p"
	.string "Reviens demain retenter ta chance,\n"
	.string "{PLAYER}{KUN}.$"

RecifDesLegendes_Indoor_Text_PresenterAnnounceWinner:
	.string "Quel combat!\p"
	.string "Le vainqueur est... {PLAYER}{KUN}!$"

RecifDesLegendes_Indoor_Text_PresenterHype:
	.string "Mesdames, messieurs... Nous\n"
	.string "entamons les HUITIEMES DE FINALE!\p"
	.string "Ce combat s'annonce explosif!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceGeeta:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, la Championne\n"
	.string "de la Ligue de PALDEA... ALISMA!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceLeon:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, le Champion\n"
	.string "de la Ligue de GALAR... TARAK!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceDiantha:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, la Championne\n"
	.string "de la Ligue de KALOS... DIANTHEA!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceIris:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, la Championne\n"
	.string "de la Ligue d'UNYS... IRIS!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceCynthia:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, la Championne\n"
	.string "de la Ligue de SINNOH... CYNTHIA!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceLance:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, le Maître\n"
	.string "Dragon... PETER!$"

RecifDesLegendes_Indoor_Text_PresenterIntroduceBlue:
	.string "Dans le coin gauche, notre nouveau\n"
	.string "Maître de la Ligue de HOENN,\l"
	.string "{PLAYER}{KUN}!\p"
	.string "Et dans le coin droit, l'ancien\n"
	.string "Champion de la Ligue de KANTO...\l"
	.string "BLUE!$"

RecifDesLegendes_Indoor_Text_RoundQuarterfinal:
	.string "Nous entamons les QUARTS DE\n"
	.string "FINALE!$"

RecifDesLegendes_Indoor_Text_RoundSemifinal:
	.string "Nous entamons les DEMI-FINALES!$"

RecifDesLegendes_Indoor_Text_RoundFinalHype1:
	.string "MESDAMES ET MESSIEURS!!\p"
	.string "Voici le moment que vous attendiez\n"
	.string "tous...$"

RecifDesLegendes_Indoor_Text_RoundFinalHype2:
	.string "LA FINALE DU TOURNOI DU RECIF\n"
	.string "DES LEGENDES VA COMMENCER!!$"

RecifDesLegendes_Indoor_Text_PresenterTournamentChampion:
	.string "Incroyable!\p"
	.string "{PLAYER}{KUN} remporte le tournoi et\n"
	.string "devient le nouveau CHAMPION DU\l"
	.string "RECIF DES LEGENDES!$"

RecifDesLegendes_Indoor_Text_PresenterFaceGeeta:
	.string "Face à {PLAYER}{KUN}, la Championne\n"
	.string "de la Ligue de PALDEA... ALISMA!$"

RecifDesLegendes_Indoor_Text_PresenterFaceLeon:
	.string "Face à {PLAYER}{KUN}, le Champion\n"
	.string "de la Ligue de GALAR... TARAK!$"

RecifDesLegendes_Indoor_Text_PresenterFaceDiantha:
	.string "Face à {PLAYER}{KUN}, la Championne\n"
	.string "de la Ligue de KALOS... DIANTHEA!$"

RecifDesLegendes_Indoor_Text_PresenterFaceIris:
	.string "Face à {PLAYER}{KUN}, la Championne\n"
	.string "de la Ligue d'UNYS... IRIS!$"

RecifDesLegendes_Indoor_Text_PresenterFaceCynthia:
	.string "Face à {PLAYER}{KUN}, la Championne\n"
	.string "de la Ligue de SINNOH... CYNTHIA!$"

RecifDesLegendes_Indoor_Text_PresenterFaceLance:
	.string "Face à {PLAYER}{KUN}, le Maître\n"
	.string "Dragon... PETER!$"

RecifDesLegendes_Indoor_Text_PresenterFaceBlue:
	.string "Face à {PLAYER}{KUN}, l'ancien\n"
	.string "Champion de la Ligue de KANTO...\l"
	.string "BLUE!$"

RecifDesLegendes_Indoor_Text_GeetaBattleIntro:
	.string "Voyons ce que tu vaux\n"
	.string "vraiment.$"

RecifDesLegendes_Indoor_Text_GeetaBattleDefeat:
	.string "...Impressionnant. Ce n'est\n"
	.string "que partie remise.$"

RecifDesLegendes_Indoor_Text_LeonBattleIntro:
	.string "Yaahoo! Prépare-toi à un\n"
	.string "combat DE FOLIE!$"

RecifDesLegendes_Indoor_Text_LeonBattleDefeat:
	.string "Woooah! Quel combat!\n"
	.string "Chapeau, {PLAYER}{KUN}!$"

RecifDesLegendes_Indoor_Text_DianthaBattleIntro:
	.string "Que le spectacle\n"
	.string "commence.$"

RecifDesLegendes_Indoor_Text_DianthaBattleDefeat:
	.string "Magnifique... Un vrai\n"
	.string "final en beauté.$"

RecifDesLegendes_Indoor_Text_IrisBattleIntro:
	.string "Je vais te montrer la force\n"
	.string "d'un vrai Maître Dragon!$"

RecifDesLegendes_Indoor_Text_IrisBattleDefeat:
	.string "Quoi?! Comment... Pas mal du\n"
	.string "tout!$"

RecifDesLegendes_Indoor_Text_CynthiaBattleIntro:
	.string "Montre-moi jusqu'où le lien\n"
	.string "avec tes Pokémon peut te mener.$"

RecifDesLegendes_Indoor_Text_CynthiaBattleDefeat:
	.string "...Voilà qui était\n"
	.string "instructif. Bien joué.$"

RecifDesLegendes_Indoor_Text_LanceBattleIntro:
	.string "Un Maître ne recule devant\n"
	.string "aucun défi. En garde!$"

RecifDesLegendes_Indoor_Text_LanceBattleDefeat:
	.string "...Tu as ma reconnaissance,\n"
	.string "dresseur.$"

RecifDesLegendes_Indoor_Text_BlueBattleIntro:
	.string "Ne t'attends pas à ce que je\n"
	.string "te fasse de cadeau.$"

RecifDesLegendes_Indoor_Text_BlueBattleDefeat:
	.string "Tch... T'es pas si nul, en\n"
	.string "fait.$"
