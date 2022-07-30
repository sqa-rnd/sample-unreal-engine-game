// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameUIWidget.h"

#include <string>

#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

void SGameUIWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;
	Score = 10;

	const FText ScoreLabelText = LOCTEXT("ScoreLabel", "Score: {0}");

	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 30.f;

	const FMargin TextPadding = FMargin(50.f);
	
	ChildSlot
	[
	SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(TextPadding)
		[
		SNew(SVerticalBox)
		    + SVerticalBox::Slot()
			[
				SNew(STextBlock)
				.Font(TextStyle)
				.Text(FText::Format(ScoreLabelText, FText::AsNumber(Score)))
				.Justification(ETextJustify::Left)
			]
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
