SkyPillar_5F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SkyPillar_5F_OnTransition
	.byte 0

SkyPillar_5F_OnTransition:
	call_if_lt VAR_SKY_PILLAR_STATE, 2, SkyPillar_5F_EventScript_CleanFloor
	return

SkyPillar_5F_EventScript_CleanFloor::
	setmaplayoutindex LAYOUT_SKY_PILLAR_5F_CLEAN
	return

SkyPillar_5F_EventScript_DeltaSage::
	trainerbattle_single TRAINER_DELTA_SAGE, SkyPillar_5F_Text_DeltasSageIntro, SkyPillar_5F_Text_DeltasSageDefeat
	msgbox SkyPillar_5F_Text_DeltasSagePostBattle, MSGBOX_AUTOCLOSE
	end

SkyPillar_5F_Text_DeltasSageIntro:
	.string "Before facing RAYQUAZA\n"
	.string "you must be proven!$"

SkyPillar_5F_Text_DeltasSageDefeat:
	.string "You've proven yourself,\n"
	.string "now save the world.$"

SkyPillar_5F_Text_DeltasSagePostBattle:
	.string "RAYQUAZA will help you\n"
	.string "stopping those legendaries.$"
