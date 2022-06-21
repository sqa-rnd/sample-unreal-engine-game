// Copyright Epic Games, Inc. All Rights Reserved.


#include "SampleGameGameModeBase.h"

#include "MenuHUD.h"
#include "MenuPlayerController.h"

ASampleGameGameModeBase::ASampleGameGameModeBase()
{
	PlayerControllerClass = AMenuPlayerController::StaticClass();
	HUDClass = AMenuHUD::StaticClass();
}
