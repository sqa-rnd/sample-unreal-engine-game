// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SAMPLEGAME_API SGameUIWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameUIWidget){}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwningHUD)
	SLATE_ATTRIBUTE(int32, Score)
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	FText GetCurrentScore() const;
	FReply OnMenuClicked() const;

	TWeakObjectPtr<class AGameHUD> OwningHUD;
	
};
