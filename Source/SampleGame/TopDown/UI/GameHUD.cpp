﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"

#include "SGameUIWidget.h"
#include "SPauseMenuWidget.h"
#include "Kismet/GameplayStatics.h"


void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	ShowGameUI();
	SetInputModeToGame();
}

void AGameHUD::ShowPauseMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		PauseMenuWidget = SNew(SPauseMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(WidgetContainer, SWeakWidget)
			.PossiblyNullContent(PauseMenuWidget.ToSharedRef()));

		SetInputModeToUI();
	}
}

void AGameHUD::HidePauseMenu()
{
	if(GEngine && GEngine->GameViewport && WidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(WidgetContainer.ToSharedRef());
		SetInputModeToGame();
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

void AGameHUD::SetInputModeToUI()
{
	if(PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}

void AGameHUD::SetInputModeToGame()
{
	if(PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = false;
		PlayerOwner->SetInputMode(FInputModeGameOnly());
	}
}
