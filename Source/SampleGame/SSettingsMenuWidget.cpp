#include "SSettingsMenuWidget.h"
#include "MenuHUD.h"
#include "Components/OverlaySlot.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "Widgets/Input/STextComboBox.h"

#define LOCTEXT_NAMESPACE "SettingsWidget"

void SSettingsMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 100.f);
	const FMargin ButtonPadding = FMargin(10.f);

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo CheckBoxTextStyle = ButtonTextStyle;
	CheckBoxTextStyle.Size = 16.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	FSlateRenderTransform Scale = FSlateRenderTransform(2);

	TArray<TSharedPtr<FString>> TextComboBoxOptions;
	TextComboBoxOptions.Add(MakeShareable(new FString(TEXT("Option 1"))));
	TextComboBoxOptions.Add(MakeShareable(new FString(TEXT("Option 2"))));
	TextComboBoxOptions.Add(MakeShareable(new FString(TEXT("Option 3"))));

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
					.Text(LOCTEXT("Title", "Settings"))
					.Justification(ETextJustify::Center)
					.AddMetaData(FDriverMetaData::Id("SettingsTitle"))
			]
			// Text Field
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SEditableTextBox)
				.Font(ButtonTextStyle)
				.AddMetaData(FDriverMetaData::Id("TextInputField"))
			]
			// Text Dropdown TODO: doesn't work for now
			+ SVerticalBox::Slot()
			  .Padding(0.0f, 5.0f)
			  .HAlign(HAlign_Fill)
			  .VAlign(VAlign_Center)
			[
				SAssignNew(TextComboBox, STextComboBox)
					.Font(ButtonTextStyle)
					.OptionsSource(&TextComboBoxOptions)
					.OnSelectionChanged(this, &SSettingsMenuWidget::HandleTextComboBoxSelectionChanged)
					.InitiallySelectedItem(TextComboBoxOptions.Top())
					.AddMetaData(FDriverMetaData::Id("ComboBox"))
			]
			+ SVerticalBox::Slot()
			[
				SNew(SUniformGridPanel)
				+ SUniformGridPanel::Slot(0, 0)
				[
					// Checkboxes 
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox01"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel01", "CheckBox 1"))
							.AddMetaData(FDriverMetaData::Id("CheckBox01_Text"))
						]
					]
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox02"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel02", "CheckBox 2"))
							.AddMetaData(FDriverMetaData::Id("CheckBox02_Text"))
						]
					]
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox03"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel03", "CheckBox 3"))
							.AddMetaData(FDriverMetaData::Id("CheckBox03_Text"))
						]
					]
				]
				// Radio buttons 
				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.Style(FCoreStyle::Get(), "RadioButton")
						.IsChecked(this, &SSettingsMenuWidget::HandleRadioButtonIsChecked, Radio0)
						.OnCheckStateChanged(this, &SSettingsMenuWidget::HandleRadioButtonCheckStateChanged, Radio0)
						.AddMetaData(FDriverMetaData::Id("RadioGroup_Button01"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("RadioButtonLabel01", "Radio 1"))
							.AddMetaData(FDriverMetaData::Id("RadioGroup_Button01_Text"))
						]
					]
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.Style(FCoreStyle::Get(), "RadioButton")
						.IsChecked(this, &SSettingsMenuWidget::HandleRadioButtonIsChecked, Radio1)
						.OnCheckStateChanged(this, &SSettingsMenuWidget::HandleRadioButtonCheckStateChanged, Radio1)
						.AddMetaData(FDriverMetaData::Id("RadioGroup_Button02"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("RadioButtonLabel02", "Radio 2"))
							.AddMetaData(FDriverMetaData::Id("RadioGroup_Button02_Text"))
						]
					]
					+ SVerticalBox::Slot()
					[
						SNew(SCheckBox)
						.RenderTransform(Scale)
						.Style(FCoreStyle::Get(), "RadioButton")
						.IsChecked(this, &SSettingsMenuWidget::HandleRadioButtonIsChecked, Radio2)
						.OnCheckStateChanged(this, &SSettingsMenuWidget::HandleRadioButtonCheckStateChanged, Radio2)
						.AddMetaData(FDriverMetaData::Id("RadioGroup_Button03"))
						[
							SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("RadioButtonLabel03", "Radio 3"))
							.AddMetaData(FDriverMetaData::Id("RadioGroup_Button03_Text"))
						]
					]
				]
			]
			// Slider
			+ SVerticalBox::Slot()
			[
				SNew(SSlider)
				.Orientation(Orient_Horizontal)
				.Value(0.5f)
				.AddMetaData(FDriverMetaData::Id("Slider"))
			]
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsMenuWidget::OnBackClicked)
				.VAlign(VAlign_Center)
				.AddMetaData(FDriverMetaData::Id("BackButton"))
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(LOCTEXT("BackToMenu", "Back"))
					.Justification(ETextJustify::Center)
					.AddMetaData(FDriverMetaData::Id("BackButton_Text"))
				]
			]
		]
	];
}

FReply SSettingsMenuWidget::OnBackClicked()
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveSettingsMenu();
		OwningHUD->ShowMenu();
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
