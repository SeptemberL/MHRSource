// Copyright Epic Games, Inc. All Rights Reserved.

#include "MHRProjectGameMode.h"
#include "MHRProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMHRProjectGameMode::AMHRProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
