// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * 
 */
class SAMPLEGAME_API SPauseMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPauseMenuWidget){}
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwningHUD)
	SLATE_END_ARGS()
	
	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FReply OnResumeClicked() const;
	FReply OnRestartClicked() const;
	FReply OnQuitClicked() const;

	TWeakObjectPtr<class AGameHUD> OwningHUD;
};
