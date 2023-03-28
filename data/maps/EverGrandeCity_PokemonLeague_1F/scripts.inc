.set LOCALID_NURSE, 1
.set LOCALID_GUARD_1, 3
.set LOCALID_GUARD_2, 4
.set LOCALID_RIVAL, 5

EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	call Common_EventScript_SetupRivalGfxId
	call_if_unset FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GuardsBlockDoor::
	setobjectxyperm LOCALID_GUARD_1, 9, 2
	setobjectxyperm LOCALID_GUARD_2, 10, 2
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EverGrandeCity_PokemonLeague_1F_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ABILITY_CAPSULE
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_NONE
	release
	end

@ The door guards only check for FLAG_BADGE06_GET because Winonas badge is the only one that can be skipped
@ Its assumed the player has the remaining badges
EverGrandeCity_PokemonLeague_1F_EventScript_DoorGuard::
	lockall
	goto_if_set FLAG_ENTERED_ELITE_FOUR, EverGrandeCity_PokemonLeague_1F_EventScript_GoForth
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_ge VAR_TEMP_0, 11, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight
	call_if_le VAR_TEMP_0, 8, EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft
	message EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges
	waitmessage
	delay 120
	goto_if_unset FLAG_BADGE06_GET, EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges
	closemessage
	applymovement LOCALID_GUARD_1, EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay
	applymovement LOCALID_GUARD_2, EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay
	waitmovement 0
	delay 10
	playfanfare MUS_OBTAIN_BADGE
	message EverGrandeCity_PokemonLeague_1F_Text_GoForth
	waitmessage
	waitfanfare
	closemessage
	copyobjectxytoperm LOCALID_GUARD_1
	copyobjectxytoperm LOCALID_GUARD_2
	setflag FLAG_ENTERED_ELITE_FOUR
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromRight::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_PlayerMoveToFrontFromLeft::
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft
	waitmovement 0
	return

EverGrandeCity_PokemonLeague_1F_EventScript_NotAllBadges::
	playse SE_FAILURE
	msgbox EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges, MSGBOX_DEFAULT
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_EventScript_GoForth::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_PokemonLeague_1F_Text_GoForth, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromRight:
	walk_down
	walk_left
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_MoveToFrontFromLeft:
	walk_down
	walk_right
	walk_in_place_faster_up
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_LeftGuardOutOfWay:
	walk_left
	walk_in_place_faster_down
	step_end

EverGrandeCity_PokemonLeague_1F_Movement_RightGuardOutOfWay:
	walk_right
	walk_in_place_faster_down
	step_end

PokemonLeague_EventScript_Rival::
	lockall
	call_if_unset FLAG_MET_RIVAL_LEAGUE, PokemonLeague_EventScript_PlayRivalMusic
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto PokemonLeague_EventScript_RivalEncounter

PokemonLeague_EventScript_PlayRivalMusic::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonLeague_EventScript_PlayMayMusic
	goto_if_eq VAR_RESULT, FEMALE, PokemonLeague_EventScript_PlayBrendanMusic
	return

PokemonLeague_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

PokemonLeague_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

PokemonLeague_EventScript_RivalTrigger0::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, PokemonLeague_Movement_Rival0
	waitmovement 0
	goto PokemonLeague_EventScript_Rival

PokemonLeague_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, PokemonLeague_Movement_Rival1
	goto PokemonLeague_EventScript_Rival

PokemonLeague_Movement_Rival0:
	walk_left
	face_down
	step_end

PokemonLeague_Movement_Rival1:
	face_down
	step_end


PokemonLeague_EventScript_RivalEncounter::
	setvar VAR_EVER_GRANDE_CITY_STATE, 1
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PokemonLeague_EventScript_MayEncounter
	goto_if_eq VAR_RESULT, FEMALE, PokemonLeague_EventScript_BrendanEncounter
	end

PokemonLeague_EventScript_MayEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_LEAGUE, PokemonLeague_EventScript_RivalPostBattle
	/*goto_if_set FLAG_MET_RIVAL_LEAGUE, PokemonLeague_EventScript_MayAskToBattle*/
	setflag FLAG_MET_RIVAL_LEAGUE
	delay 30
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_BattleMay
	/*msgbox PokemonLeague_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonLeague_EventScript_BattleRival
	msgbox PokemonLeague_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call PokemonLeague_EventScript_RestoreBgm
	*/
	releaseall
	end

PokemonLeague_EventScript_BrendanEncounter::
	goto_if_set FLAG_DEFEATED_RIVAL_LEAGUE, PokemonLeague_EventScript_RivalPostBattle
	/*goto_if_set FLAG_MET_RIVAL_LEAGUE, PokemonLeague_EventScript_MayAskToBattle*/
	setflag FLAG_MET_RIVAL_LEAGUE
	delay 30
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_BattleBrendan
	/*msgbox PokemonLeague_Text_MayPassedBrineyWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonLeague_EventScript_BattleRival
	msgbox PokemonLeague_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	call PokemonLeague_EventScript_RestoreBgm
	*/
	releaseall
	end

/*PokemonLeague_EventScript_MayAskToBattle::
	setvar VAR_0x8008, 1
	msgbox PokemonLeague_Text_MayWantToBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PokemonLeague_EventScript_BattleMay
	msgbox PokemonLeague_Text_MayOhHaventRaisedPokemonEnough, MSGBOX_DEFAULT
	releaseall
	end
*/	

PokemonLeague_EventScript_RivalPostBattle::
	msgbox PokemonLeague_Text_RivalPostBattle, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PokemonLeague_EventScript_RestoreBgm
	releaseall
	end

PokemonLeague_EventScript_BattleMay::
	setvar VAR_0x8008, 1
	msgbox PokemonLeague_Text_RivalImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, PokemonLeague_EventScript_BattleMayTreecko
	case 1, PokemonLeague_EventScript_BattleMayTorchic
	case 2, PokemonLeague_EventScript_BattleMayMudkip
	end

PokemonLeague_EventScript_BattleBrendan::
	setvar VAR_0x8008, 1
	msgbox PokemonLeague_Text_RivalImNotGoingToLose, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, PokemonLeague_EventScript_BattleBrendanTreecko
	case 1, PokemonLeague_EventScript_BattleBrendanTorchic
	case 2, PokemonLeague_EventScript_BattleBrendanMudkip
	end

PokemonLeague_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LEAGUE_TREECKO, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LEAGUE_TORCHIC, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LEAGUE_MUDKIP, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LEAGUE_TREECKO, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LEAGUE_TORCHIC, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LEAGUE_MUDKIP, PokemonLeague_Text_RivalDefeat
	setflag FLAG_DEFEATED_RIVAL_LEAGUE
	setvar VAR_0x8008, 0
	goto PokemonLeague_EventScript_RivalPostBattle
	end

PokemonLeague_EventScript_RestoreBgm::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

PokemonLeague_Text_RivalImNotGoingToLose:
	.string "{RIVAL}: {PLAYER}{KUN}, this time,\n"
	.string "I'm really not going to lose!$"

PokemonLeague_Text_RivalDefeat:
	.string "Incredible!\n"
	.string "With this strength, you have surely\l"
	.string "great chances to become CHAMP!$"

PokemonLeague_Text_RivalPostBattle:
	.string "{RIVAL}: You are a very strong trainer!$"

EverGrandeCity_PokemonLeague_1F_Text_MustHaveAllGymBadges:
	.string "Beyond this point, only those TRAINERS\n"
	.string "who have collected all the GYM BADGES\l"
	.string "are permitted to enter.\p"
	.string "TRAINER, let us confirm that you have\n"
	.string "all the GYM BADGES.$"

EverGrandeCity_PokemonLeague_1F_Text_HaventObtainedAllBadges:
	.string "You haven't obtained all the BADGES.\p"
	.string "If you're bound for the POKéMON\n"
	.string "LEAGUE, you must return with them.$"

EverGrandeCity_PokemonLeague_1F_Text_GoForth:
	.string "TRAINER! Believe in yourself and your\n"
	.string "POKéMON, and go forth!$"

