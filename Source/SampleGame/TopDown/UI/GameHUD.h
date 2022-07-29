// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SampleGame/MainMenu/SMainMenuWidget.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	void ShowPauseMenu();
	void HidePauseMenu();

	void ShowGameUI();

	virtual void BeginPlay() override;
	
protected:
	TSharedPtr<class SPauseMenuWidget> PauseMenuWidget;
	TSharedPtr<class SWidget> WidgetContainer;
	TSharedPtr<class SGameUIWidget> GameUIWidget;
};
