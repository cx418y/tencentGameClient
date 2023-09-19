// Copyright Epic Games, Inc. All Rights Reserved.

#include "myGameGameMode.h"
#include "myGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AmyGameGameMode::AmyGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
