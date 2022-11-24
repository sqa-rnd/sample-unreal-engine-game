// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuWidget.h"

#include "MenuHUD.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "SampleGame"

void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;
	
	OwningHUD = InArgs._OwningHUD;
	
	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);
	
	const FText TitleText = LOCTEXT("GameTitle", "My Super Great Game");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingsText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;
	
	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.ColorAndOpacity(FColor::Black)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				SNew(SVerticalBox)

				//Title text
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TitleTextStyle)
					.Text(TitleText)
					.Justification(ETextJustify::Center)
					.AddMetaData(FDriverMetaData::Id("MainMenuTitle"))
				]

				//Play button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SMainMenuWidget::OnPlayClicked)
					.AddMetaData(FDriverMetaData::Id("PlayButton"))
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(PlayText)
						.AddMetaData(FDriverMetaData::Id("PlayButtonText"))
						.Justification(ETextJustify::Center)
					]
				]

				//Settings button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SMainMenuWidget::OnSettingsClicked)
					.AddMetaData(FDriverMetaData::Id("SettingsButton"))
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(SettingsText)
						.AddMetaData(FDriverMetaData::Id("SettingsButtonText"))
						.Justification(ETextJustify::Center)
					]
				]

				//Quit button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
					.AddMetaData(FDriverMetaData::Id("QuitButton"))
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.AddMetaData(FDriverMetaData::Id("QuitButtonText"))
						.Justification(ETextJustify::Center)
					]
				]
			]
		];
}

FReply SMainMenuWidget::OnPlayClicked() const
{
	UWorld* MyWorld = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	FLatentActionInfo LatentInfo;
	UGameplayStatics::UnloadStreamLevel(MyWorld, "MainMenu", LatentInfo, false);
	UGameplayStatics::OpenLevel(MyWorld, "TopDownExampleMap");
	
	return FReply::Handled();
}


FReply SMainMenuWidget::OnSettingsClicked() const
{
	if(OwningHUD.IsValid())
	{
		OwningHUD->HideMainMenu();
		OwningHUD->ShowSettingsMenu();
	}
	
	return FReply::Handled();
}

FReply SMainMenuWidget::OnQuitClicked() const
{
	if(OwningHUD.IsValid())
	{
		if(APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
