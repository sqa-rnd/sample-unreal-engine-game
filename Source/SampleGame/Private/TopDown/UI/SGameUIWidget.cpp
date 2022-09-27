// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameUIWidget.h"

#include <string>

#include "GameHUD.h"
#include "SlateOptMacros.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "Kismet/GameplayStatics.h"
#include "SampleGame/Private/TopDown/TP_TopDownCharacter.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

const FText ScoreLabelText = LOCTEXT("ScoreLabel", "Score: {0}");

void SGameUIWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;

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
				.Text(this, &SGameUIWidget::GetCurrentScore)
				.Justification(ETextJustify::Left)
				.AddMetaData(FDriverMetaData::Id("Score"))
			]
		]
	];
}

FText SGameUIWidget::GetCurrentScore() const
{
	UWorld* MyWorld = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	ACharacter* Player = UGameplayStatics::GetPlayerCharacter(MyWorld,0);
	ATP_TopDownCharacter* TopDownCharacter = Cast<ATP_TopDownCharacter>(Player);

	return FText::Format(ScoreLabelText, FText::AsNumber(TopDownCharacter->GetScore()));
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
