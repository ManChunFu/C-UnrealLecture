// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CPPUnrealLectureGameMode.h"
#include "CPPUnrealLectureHUD.h"
#include "CPPUnrealLectureCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPUnrealLectureGameMode::ACPPUnrealLectureGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACPPUnrealLectureHUD::StaticClass();
}
