// Fill out your copyright notice in the Description page of Project Settings.


#include "SPauseMenuWidget.h"

#include "SlateOptMacros.h"
#include "Widgets/Images/SImage.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

#define LOCTEXT_NAMESPACE "SampleGame"

void SPauseMenuWidget::Construct(const FArguments& InArgs)
{
	const FMargin ContentPadding = FMargin(500.f, 300.f);

	const FText TitleText = LOCTEXT("PauseMenuTitle", "Pause Menu");
	
	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			SNew(SImage)
			.ColorAndOpacity(FColor::Blue)
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
				.Text(TitleText)
				.Justification(ETextJustify::Center)
			]
		]
	]; 
}

FReply SPauseMenuWidget::OnResumeClicked() const
{
	return FReply::Handled();
}

FReply SPauseMenuWidget::OnRestartClicked() const
{
	return FReply::Handled();
}

FReply SPauseMenuWidget::OnQuitClicked() const
{
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
