// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Surviving_GroundsGameMode.h"
#include "Surviving_GroundsHUD.h"
#include "Surviving_GroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASurviving_GroundsGameMode::ASurviving_GroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASurviving_GroundsHUD::StaticClass();
}
