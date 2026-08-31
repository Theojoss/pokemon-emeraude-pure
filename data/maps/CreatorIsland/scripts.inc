CreatorIsland_MapScripts::
	.byte 0

CreatorIsland_EventScript_Theojoss::
	lock
	goto_if_set FLAG_DEFEATED_THEOJOSS, CreatorIsland_EventScript_TheojossDefeated
	faceplayer
	msgbox CreatorIsland_Text_TheojossIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_THEOJOSS, CreatorIsland_Text_TheojossDefeatSpeech
	setflag FLAG_DEFEATED_THEOJOSS
	goto CreatorIsland_EventScript_TheojossGiveReward
	end

CreatorIsland_EventScript_TheojossDefeated::
	goto_if_set FLAG_RECEIVED_THEOJOSS_EGG, CreatorIsland_EventScript_TheojossAlreadyRewarded
	goto CreatorIsland_EventScript_TheojossGiveReward
	end

CreatorIsland_EventScript_TheojossGiveReward::
	giveitem ITEM_SHINY_CHARM
	msgbox CreatorIsland_Text_TheojossRewardAnnounce, MSGBOX_DEFAULT
	special ChooseSpeciesForEggReward
	giveegg VAR_0x8004
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, CreatorIsland_EventScript_TheojossNoRoomForEgg
	setflag FLAG_RECEIVED_THEOJOSS_EGG
	msgbox CreatorIsland_Text_TheojossGaveEgg, MSGBOX_DEFAULT
	release
	end

CreatorIsland_EventScript_TheojossNoRoomForEgg::
	msgbox CreatorIsland_Text_TheojossNoRoom, MSGBOX_DEFAULT
	release
	end

CreatorIsland_EventScript_TheojossAlreadyRewarded::
	msgbox CreatorIsland_Text_TheojossPostBattle, MSGBOX_DEFAULT
	release
	end

CreatorIsland_Text_TheojossIntro:
	.string "Alors comme ça… tu es arrivé jusqu'\n"
	.string "ici.\p"
	.string "Je dois t'avouer quelque chose: je\n"
	.string "suis le créateur de ce jeu.\p"
	.string "Et je tenais à te féliciter, d'être\n"
	.string "arrivé aussi loin.\p"
	.string "Cette version a été façonnée avec\n"
	.string "beaucoup d'affection, pour faire\l"
	.string "revivre les souvenirs d'enfance de\l"
	.string "ceux qui ont grandi avec le jeu\l"
	.string "original.\p"
	.string "Chaque recoin, chaque détail, chaque\n"
	.string "combat… c'est un peu de nostalgie\l"
	.string "que j'ai voulu transmettre.\p"
	.string "Mais trêve d'émotion! Tu vas à\n"
	.string "présent affronter un défi d'un\l"
	.string "tout autre niveau.\p"
	.string "Si tu parviens à me vaincre, une\n"
	.string "récompense à la hauteur de l'épreuve\l"
	.string "t'attend.$"

CreatorIsland_Text_TheojossDefeatSpeech:
	.string "Félicitations, {PLAYER}{KUN}.\p"
	.string "Je n'en attendais pas moins de\n"
	.string "toi.$"

CreatorIsland_Text_TheojossRewardAnnounce:
	.string "Comme promis, voici ta\n"
	.string "récompense.\p"
	.string "Choisis n'importe quel Pokémon:\n"
	.string "peu importe son espèce, sa région\l"
	.string "d'origine, même les plus\l"
	.string "légendaires d'entre eux.\p"
	.string "Je te le confierai sous la forme\n"
	.string "d'un œuf.$"

CreatorIsland_Text_TheojossGaveEgg:
	.string "Prends bien soin de cet œuf…\p"
	.string "J'ai hâte de voir ce qu'il\n"
	.string "deviendra entre tes mains.$"

CreatorIsland_Text_TheojossNoRoom:
	.string "Hmm, il semblerait que tu n'aies\n"
	.string "plus de place, ni dans ton équipe,\l"
	.string "ni au PC.\p"
	.string "Fais de la place et reviens me\n"
	.string "voir, ta récompense t'attendra\l"
	.string "toujours.$"

CreatorIsland_Text_TheojossPostBattle:
	.string "Continue comme ça,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Je serai toujours là si tu as besoin\n"
	.string "d'un adversaire à ta hauteur.$"

CreatorIsland_EventScript_Sailor::
	lock
	faceplayer
	msgbox CreatorIsland_Text_SailorReturnPrompt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CreatorIsland_EventScript_SailorStay
	msgbox CreatorIsland_Text_SailorReturnConfirm, MSGBOX_DEFAULT
	playse SE_M_SURF
	warpsilent MAP_PACIFIDLOG_TOWN, 2, 14
	waitstate
	release
	end

CreatorIsland_EventScript_SailorStay::
	closemessage
	release
	end

CreatorIsland_Text_SailorReturnPrompt:
	.string "Alors, prêt à rentrer à\n"
	.string "PACIFIVILLE?$"

CreatorIsland_Text_SailorReturnConfirm:
	.string "Très bien, en route!$"
