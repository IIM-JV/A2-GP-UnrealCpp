// Copyright Epic Games, Inc. All Rights Reserved.

#include "PlethoreDeCppGameMode.h"
#include "PlethoreDeCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

APlethoreDeCppGameMode::APlethoreDeCppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
