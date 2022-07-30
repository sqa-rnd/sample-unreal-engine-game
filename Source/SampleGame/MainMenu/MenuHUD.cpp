// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SMainMenuWidget.h"
#include "SSettingsMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	ShowMainMenu();
}

void AMenuHUD::ShowMainMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(MenuWidget.ToSharedRef()));
 	}
}

void AMenuHUD::HideMainMenu()
{
	if(GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
	}
}

void AMenuHUD::ShowSettingsMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		SettingsMenuWidget = SNew(SSettingsMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(SettingsMenuWidget.ToSharedRef()));
	}
}

void AMenuHUD::HideSettingsMenu()
{
	if(GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(SettingsMenuWidget.ToSharedRef());
	}
}
