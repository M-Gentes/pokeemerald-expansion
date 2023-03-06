PacifidlogTown_House4_MapScripts::
	.byte 0

/**
PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "People were saying they saw a POKéMON\n"
	.string "flying high above HOENN.\p"
	.string "Is it flying around all the time?\n"
	.string "Doesn't it need to rest somewhere?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "A sky POKéMON!\n"
	.string "A sky POKéMON!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Where did you come from?$"

PacifidlogTown_House4_Text_YesTown:
	.string "Yes?\n"
	.string "YES TOWN?\p"
	.string "I've never heard of a place like that.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "No? That doesn't make any sense.\n"
	.string "You have to come from somewhere.\p"
	.string "Oh! Wait! You're not going to say you\n"
	.string "were born at the bottom of the sea?$"
*/

PacifidlogTown_House4_EventScript_Rio::
	trainerbattle_single TRAINER_DOUGLAS, PacifidlogTown_House4_Text_RioIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_RioIntro:
	.string "I am Rio, a WATER Gym Leader of\n"
	.string "another region and also a firefighter.\n"
	.string "I'll extinguish your fire!$"

PacifidlogTown_House4_EventScript_Ventus::
	trainerbattle_single TRAINER_DAVID, PacifidlogTown_House4_Text_VentusIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_VentusIntro:
	.string "I am Ventus, a FLYING Gym Leader of\n"
	.string "another region and also a skydiver.\n"
	.string "Let's do a barrel roll!$"

PacifidlogTown_House4_EventScript_OchysP::
	trainerbattle_single TRAINER_MATTHEW, PacifidlogTown_House4_Text_OchysPIntro, PacifidlogTown_House4_Text_OchysPDefeated
	msgbox PacifidlogTown_House4_Text_OchysPPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_OchysPIntro:
	.string ".Mentalist a also and region another\n"
	.string "of Leader Gym PSYCHIC a, ochysP am I\n"
	.string "Mind Crush!$"

PacifidlogTown_House4_Text_OchysPDefeated:
	.string "!me defeating for Congratulations$"

PacifidlogTown_House4_Text_OchysPPostBattle:
	.string ".fight good a was That$"

PacifidlogTown_House4_EventScript_Gaia::
	trainerbattle_single TRAINER_TARA, PacifidlogTown_House4_Text_GaiaIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_GaiaIntro:
	.string "I am Gaia, a Ground Gym Leader of\n"
	.string "another region and also a gardener.\n"
	.string "Let me put you into the ground!$"

PacifidlogTown_House4_EventScript_Sannow::
	trainerbattle_single TRAINER_LINDA, PacifidlogTown_House4_Text_SannowIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_SannowIntro:
	.string "I am Sannow, a ICE Gym Leader of\n"
	.string "another region and also a snowboarder.\n"
	.string "I'll push you down the slope!$"

PacifidlogTown_House4_EventScript_Rocky::
	trainerbattle_single TRAINER_JACK, PacifidlogTown_House4_Text_RockyIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_RockyIntro:
	.string "I am Rocky, a ROCK Gym Leader of\n"
	.string "another region and also a rock star.\n"
	.string "Let's rock!$"

PacifidlogTown_House4_EventScript_Barium::
	trainerbattle_single TRAINER_HENRY, PacifidlogTown_House4_Text_BariumIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_BariumIntro:
	.string "I AM BARIUM, A STEEL GYM LEADER OF\n"
	.string "ANOTHER REGION AND ALSO A METAL DRUMMER.\n"
	.string "I'LL CRUSH YOU WITH MY HEART OF STEEL!$"

PacifidlogTown_House4_EventScript_Oscur::
	trainerbattle_single TRAINER_DEAN, PacifidlogTown_House4_Text_OscurIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_OscurIntro:
	.string "I am Oscur, a DARK Gym Leader of\n"
	.string "another region and also... a business man.\n"
	.string "Let us finish the meeting!$"

PacifidlogTown_House4_EventScript_Nina::
	trainerbattle_single TRAINER_TANYA, PacifidlogTown_House4_Text_NinaIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_NinaIntro:
	.string "I am Nina of the ELITE of\n"
	.string "another region and also a Ranger.\n"
	.string "Show me if I have made a good catch!$"

PacifidlogTown_House4_EventScript_Kazey::
	trainerbattle_single TRAINER_SUSIE, PacifidlogTown_House4_Text_KazeyIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_KazeyIntro:
	.string "I am Kazey of the ELITE of\n"
	.string "another region and also a Shaolin master.\n"
	.string "My old bones need to kick some butt!$"

PacifidlogTown_House4_EventScript_Ceniza::
	trainerbattle_single TRAINER_BEVERLY, PacifidlogTown_House4_Text_CenizaIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_CenizaIntro:
	.string "I am Ceniza of the ELITE of\n"
	.string "another region and also a summer model.\n"
	.string "Let's start a hot shooting!$"

PacifidlogTown_House4_EventScript_Elise::
	trainerbattle_single TRAINER_ALICE, PacifidlogTown_House4_Text_EliseIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_EliseIntro:
	.string "I am Elise of the ELITE of\n"
	.string "another region and also an author.\n"
	.string "Give me a flashing fight for my next book!$"

PacifidlogTown_House4_EventScript_Epikrates::
	trainerbattle_single TRAINER_AUSTINA, PacifidlogTown_House4_Text_EpikratesIntro, PacifidlogTown_House4_Text_CustomTrainersDefeated
	msgbox PacifidlogTown_House4_Text_CustomTrainersPostBattle, MSGBOX_AUTOCLOSE
	end

PacifidlogTown_House4_Text_EpikratesIntro:
	.string "So you want to fight me...\n"
	.string "I am the Champ of another region...\n"
	.string "I am called Epikrates...\n"
	.string "Be prepared for the power of mythologies!$"

PacifidlogTown_House4_Text_CustomTrainersDefeated:
	.string "Congratulations for defeating me!$"

PacifidlogTown_House4_Text_CustomTrainersPostBattle:
	.string "That was a good fight.$"
