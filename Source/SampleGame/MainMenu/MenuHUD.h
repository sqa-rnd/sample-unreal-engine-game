// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API AMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:

	TSharedPtr<class SMainMenuWidget> MenuWidget;
	TSharedPtr<class SWidget> MenuWidgetContainer;
	TSharedPtr<class SSettingsMenuWidget> SettingsMenuWidget;

	virtual void BeginPlay() override;

public:
	
	void ShowMenu();
	void RemoveMenu();
	void ShowSettingsMenu();
	void RemoveSettingsMenu();
};
