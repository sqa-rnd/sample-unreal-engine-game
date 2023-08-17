// Fill out your copyright notice in the Description page of Project Settings.


#include "SGameUIWidget.h"

#include <string>

#include "GameHUD.h"
#include "SlateOptMacros.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "Kismet/GameplayStatics.h"
#include "SampleGame/Private/TopDown/TP_TopDownCharacter.h"
#include "TopDown/TP_TopDownPlayerController.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

const FText ScoreLabelText = LOCTEXT("ScoreLabel", "Score: {0}");

void SGameUIWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;

	const FText MenuButtonText = LOCTEXT("InGameMenu", "Menu");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 10.f;
	
	FSlateFontInfo TextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TextStyle.Size = 30.f;

	const FMargin TextPadding = FMargin(50.f);
	
	ChildSlot
	[
	SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Top)
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
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
			     SNew(SButton)
				.OnClicked(this, &SGameUIWidget::OnMenuClicked)
				.AddMetaData(FDriverMetaData::Id("MenuButton"))
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(MenuButtonText)
					.Justification(ETextJustify::Left)
				]
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

FReply SGameUIWidget::OnMenuClicked() const
{
	UWorld* MyWorld = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(MyWorld,0);
	ATP_TopDownPlayerController* ATP_PlayerController = Cast<ATP_TopDownPlayerController>(PlayerController);
	ATP_PlayerController->OpenPauseMenu();
	
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
