// Copyright Epic Games, Inc. All Rights Reserved.


#include "MainMenuGameMode.h"

#include "MenuHUD.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	HUDClass = AMenuHUD::StaticClass();
}
