// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuPlayerController.h"

#include "MenuHUD.h"

AMenuPlayerController::AMenuPlayerController()
{
}

void AMenuPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
}

// void AMenuPlayerController::OpenMenu()
// {
// 	if(AMenuHUD* MenuHUD = Cast<AMenuHUD>(GetHUD()))
// 	{
// 		MenuHUD->ShowMenu();
// 	}
// }
