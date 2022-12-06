// Copyright Epic Games, Inc. All Rights Reserved.

#include "HexGridSystemGameMode.h"
#include "HexGridSystemPlayerController.h"
#include "HexGridSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHexGridSystemGameMode::AHexGridSystemGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AHexGridSystemPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}