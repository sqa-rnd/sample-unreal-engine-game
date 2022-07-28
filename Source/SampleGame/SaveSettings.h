// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSettingsMenuWidget.h"
#include "GameFramework/SaveGame.h"
#include "SaveSettings.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLEGAME_API USaveSettings : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FText EditableTextBoxValue;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	TArray<bool> CheckBoxesState;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	TArray<bool> RadioButtonsState;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	float SliderValue;
	
	USaveSettings();
};
