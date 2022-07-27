// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainMenuGameMode.h"

#include "MenuHUD.h"
#include "MenuPlayerController.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
