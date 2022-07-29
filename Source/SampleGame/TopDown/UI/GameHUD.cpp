// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "SGameUIWidget.h"
#include "SPauseMenuWidget.h"

void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowGameUI();
}

void AGameHUD::ShowPauseMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		PauseMenuWidget = SNew(SPauseMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget)
			.PossiblyNullContent(PauseMenuWidget.ToSharedRef()));

		// if(PlayerOwner)
		// {
		// 	PlayerOwner->bShowMouseCursor = true;
		// 	PlayerOwner->SetInputMode(FInputModeUIOnly());
		// }
	}
}

void AGameHUD::HidePauseMenu()
{
	if(GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());

		if(PlayerOwner)
		{
			PlayerOwner->bShowMouseCursor = false;
			PlayerOwner->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AGameHUD::ShowGameUI()
{
	GameUIWidget = SNew(SGameUIWidget).OwningHUD(this);
	
	if(GEngine && GEngine->GameViewport)
	{
		GameUIWidget = SNew(SGameUIWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget)
			.PossiblyNullContent(GameUIWidget.ToSharedRef()));
	}
}
