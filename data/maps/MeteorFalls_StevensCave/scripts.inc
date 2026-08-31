MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	msgbox MeteorFalls_StevensCave_Text_TournamentAnnouncement, MSGBOX_DEFAULT
	giveitem_msg MeteorFalls_StevensCave_Text_TournamentTicketGiven, ITEM_RECIF_TICKET, 1, MUS_RG_OBTAIN_KEY_ITEM
	setflag FLAG_ENABLE_SHIP_RECIF_DES_LEGENDES
	setflag FLAG_RECEIVED_RECIF_TICKET
	msgbox MeteorFalls_StevensCave_Text_TournamentTicketExplanation, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PIERRE: Oh, waouh, {PLAYER}{KUN}. Je suis\n"
	.string "surpris que tu aies su où me trouver.\p"
	.string "Est-ce que… tu me considères juste\n"
	.string "comme un maniaque du type ROCHE?\p"
	.string "Non, je ne pense pas…\p"
	.string "Nous nous sommes battus côte à côte\n"
	.string "au CENTRE SPATIAL d'ALGATIA.\p"
	.string "Tu dois savoir mieux que quiconque de\n"
	.string "quelle façon je me bats.\p"
	.string "OK, {PLAYER}{KUN}, si tu cherches un vrai défi,\n"
	.string "je suis ton homme!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi… Je ne pensais pas que tu\n"
	.string "avais progressé à ce point…$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE: En y repensant, j'en avais eu la\n"
	.string "certitude lors de notre première\p"
	.string "rencontre à la GROTTE GRANITE\n"
	.string "du VILLAGE MYOKARA.\p"
	.string "Ma première impression est souvent la\n"
	.string "bonne.$"

MeteorFalls_StevensCave_Text_TournamentAnnouncement:
	.string "J'ai une proposition à te faire.\p"
	.string "J'ai décidé d'organiser un tournoi\n"
	.string "ici, à HOENN, réunissant les plus\l"
	.string "grands Maîtres de toutes les\l"
	.string "régions.\p"
	.string "Un vrai rassemblement des meilleurs\n"
	.string "dresseurs, loin des sentiers battus.\p"
	.string "Après ce combat, je suis convaincu\n"
	.string "que tu as ta place parmi les\l"
	.string "participants.\p"
	.string "Tiens, prends ceci.$"

MeteorFalls_StevensCave_Text_TournamentTicketGiven:
	.string "{PLAYER} a reçu le BILLET RECIF!$"

MeteorFalls_StevensCave_Text_TournamentTicketExplanation:
	.string "PIERRE: Ce billet te permettra de\n"
	.string "rejoindre le RECIF DES LEGENDES à\l"
	.string "bord du MARINA, au port de\l"
	.string "NENUCRIQUE.\p"
	.string "Le tournoi t'y attend.\n"
	.string "Bonne chance, {PLAYER}{KUN}.$"

