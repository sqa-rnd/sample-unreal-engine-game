// Fill out your copyright notice in the Description page of Project Settings.


#include "SPauseMenuWidget.h"

#include "GameHUD.h"
#include "SlateOptMacros.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "Kismet/GameplayStatics.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

void SPauseMenuWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;

	const FText TitleText = LOCTEXT("PauseMenuTitle", "Pause Menu");
	const FText ResumeText = LOCTEXT("ResumeButton", "Resume");
	const FText RestartText = LOCTEXT("RestartButton", "Restart");
	const FText QuitText = LOCTEXT("QuitButton", "Quit");
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	FSlateFontInfo TitleTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	TitleTextStyle.Size = 30.f;

	FSlateFontInfo ButtonTextStyle = TitleTextStyle;
	ButtonTextStyle.Size = 20.f;
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		.Padding(ContentPadding)
		[
		SNew(SVerticalBox)

			//Title text
			+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TitleTextStyle)
					.Text(TitleText)
					.AddMetaData(FDriverMetaData::Id("PauseMenuTitle"))
					.Justification(ETextJustify::Center)
				]

				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SPauseMenuWidget::OnResumeClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(ResumeText)
						.AddMetaData(FDriverMetaData::Id("ResumeButton"))
						.Justification(ETextJustify::Center)
					]
				]

				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SPauseMenuWidget::OnRestartClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(RestartText)
						.AddMetaData(FDriverMetaData::Id("RestartButton"))
						.Justification(ETextJustify::Center)
					]
				]

				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SPauseMenuWidget::OnQuitClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.AddMetaData(FDriverMetaData::Id("QuitButton"))
						.Justification(ETextJustify::Center)
					]
				]	
		]
	]; 
}

FReply SPauseMenuWidget::OnResumeClicked() const
{
	if(OwningHUD.IsValid())
	{
		OwningHUD->HidePauseMenu();
	}
	
	return FReply::Handled();
}

FReply SPauseMenuWidget::OnRestartClicked() const
{
	UWorld* MyWorld = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	OwningHUD->HidePauseMenu();
	UGameplayStatics::OpenLevel(MyWorld, "TopDownExampleMap");
	
	return FReply::Handled();
}

FReply SPauseMenuWidget::OnQuitClicked() const
{
	UWorld* MyWorld = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	UGameplayStatics::OpenLevel(MyWorld, "MainMenu");
	
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
