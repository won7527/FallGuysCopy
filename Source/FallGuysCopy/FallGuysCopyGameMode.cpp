// Copyright Epic Games, Inc. All Rights Reserved.

#include "FallGuysCopyGameMode.h"
#include "FallGuysCopyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFallGuysCopyGameMode::AFallGuysCopyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
