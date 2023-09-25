// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class SAMPLEGAME_API UIInventoryItem
{
public:
	UIInventoryItem();

	explicit UIInventoryItem(const FText& DisplayName)
		: DisplayName(DisplayName)
	{
	}

	~UIInventoryItem();

	FText DisplayName;
	// UTexture2D* Icon;
	
};
