// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameUIWidget.h"

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

void SGameUIWidget::Construct(const FArguments& InArgs)
{

	const FText ScoreLabelText = LOCTEXT("ScoreLabel", "Score:");
	
	ChildSlot
	[
	SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
		SNew(SVerticalBox)
		    + SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Text(ScoreLabelText)
				.Justification(ETextJustify::Center)
			]
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
