// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuHUD.h"
#include "SMainMenuWidget.h"
#include "SSettingsMenuWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine/Engine.h"

#if PLATFORM_WINDOWS
#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows.h"
#endif

void AMenuHUD::BeginPlay()
{
	Super::BeginPlay();

#if PLATFORM_WINDOWS
	const HWND GameHWND = (HWND)GEngine->GameViewport->GetWindow()->GetNativeWindow()->GetOSWindowHandle();

	::SetWindowPos(GameHWND, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	::SetWindowPos(GameHWND, HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	::SetForegroundWindow(GameHWND);
	::SetCapture(GameHWND);
	::SetFocus(GameHWND);
	::SetActiveWindow(GameHWND);
#endif

	ShowMainMenu();
	SetInputModeToUI();
}

void AMenuHUD::ShowMainMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		MenuWidget = SNew(SMainMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(MenuWidget.ToSharedRef()));
	}
}

void AMenuHUD::HideMainMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(MenuWidgetContainer.ToSharedRef());
	}
}

void AMenuHUD::ShowSettingsMenu()
{
	if (GEngine && GEngine->GameViewport)
	{
		SettingsMenuWidget = SNew(SSettingsMenuWidget).OwningHUD(this);
		GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(MenuWidgetContainer, SWeakWidget)
			.PossiblyNullContent(SettingsMenuWidget.ToSharedRef()));
	}
}

void AMenuHUD::HideSettingsMenu()
{
	if (GEngine && GEngine->GameViewport && MenuWidgetContainer.IsValid())
	{
		GEngine->GameViewport->RemoveViewportWidgetContent(SettingsMenuWidget.ToSharedRef());
	}
}

void AMenuHUD::SetInputModeToUI()
{
	if (PlayerOwner)
	{
		PlayerOwner->bShowMouseCursor = true;
		PlayerOwner->SetInputMode(FInputModeUIOnly());
	}
}
