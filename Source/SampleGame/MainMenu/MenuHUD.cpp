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

		// if(PlayerOwner)
		// {
		// 	PlayerOwner->bShowMouseCursor = true;
		// 	PlayerOwner->SetInputMode(FInputModeUIOnly());
		// }
 	}
}

void AMenuHUD::HideMainMenu()
{
	if(GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());

		// if(PlayerOwner)
		// {
		// 	PlayerOwner->bShowMouseCursor = false;
		// 	PlayerOwner->SetInputMode(FInputModeGameOnly());
		// }
	}
}

void AMenuHUD::ShowSettingsMenu()
{
	if(GEngine && GEngine->GameViewport)
	{
		SettingsMenuWidget = SNew(SSettingsMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(SettingsMenuWidget.ToSharedRef()));

		// if(PlayerOwner)
		// {
		// 	PlayerOwner->bShowMouseCursor = true;
		// 	PlayerOwner->SetInputMode(FInputModeUIOnly());
		// }
	}
}

void AMenuHUD::HideSettingsMenu()
{
	if(GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(SettingsMenuWidget.ToSharedRef());

		// if(PlayerOwner)
		// {
		// 	PlayerOwner->bShowMouseCursor = false;
		// 	PlayerOwner->SetInputMode(FInputModeGameOnly());
		// }
	}
}
