#include "SSettingsMenuWidget.h"
#include "MenuHUD.h"
#include "Components/OverlaySlot.h"
#include "Framework/MetaData/DriverMetaData.h"
#include "SampleGame/SaveSettings.h"
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

	CheckBoxes.SetNum(3);
	RadioButtons.SetNum(3);

	TextComboBoxSelectedItem = MakeShareable(new FString(TEXT("Option 1")));
	TextComboBoxOptions.Add(TextComboBoxSelectedItem);
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
				SAssignNew(EditableTextBox, SEditableTextBox)
				.Font(ButtonTextStyle)
				.AddMetaData(FDriverMetaData::Id("TextInputField"))
			]
			+ SVerticalBox::Slot()
			  .Padding(0.0f, 5.0f)
			  .HAlign(HAlign_Fill)
			  .VAlign(VAlign_Center)
			[
				SAssignNew(TextComboBox, STextComboBox)
					.Font(ButtonTextStyle)
					.OptionsSource(&TextComboBoxOptions)
					.OnSelectionChanged(this, &SSettingsMenuWidget::HandleTextComboBoxSelectionChanged)
					.InitiallySelectedItem(TextComboBoxSelectedItem)
					.AddMetaData(FDriverMetaData::Id("ComboBox"))
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			[
				SNew(SUniformGridPanel)
				// Checkboxes 
				+ SUniformGridPanel::Slot(0, 0)
				.HAlign(HAlign_Left)
				[
					SAssignNew(CheckBoxes[0], SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox01"))
					[
						SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel01", "CheckBox 1"))
							.AddMetaData(FDriverMetaData::Id("CheckBox01_Text"))
					]
				]
				+ SUniformGridPanel::Slot(0, 1)
				.HAlign(HAlign_Left)
				[
					SAssignNew(CheckBoxes[1], SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox02"))
					[
						SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel02", "CheckBox 2"))
							.AddMetaData(FDriverMetaData::Id("CheckBox02_Text"))
					]
				]
				+ SUniformGridPanel::Slot(0, 2)
				.HAlign(HAlign_Left)
				[
					SAssignNew(CheckBoxes[2], SCheckBox)
						.RenderTransform(Scale)
						.AddMetaData(FDriverMetaData::Id("CheckBox03"))
					[
						SNew(STextBlock)
							.Font(CheckBoxTextStyle)
							.Text(LOCTEXT("CheckBoxLabel03", "CheckBox 3"))
							.AddMetaData(FDriverMetaData::Id("CheckBox03_Text"))
					]
				]
				// Radio buttons 
				+ SUniformGridPanel::Slot(1, 0)
				.HAlign(HAlign_Left)
				[
					SAssignNew(RadioButtons[0], SCheckBox)
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
				+ SUniformGridPanel::Slot(1, 1)
				.HAlign(HAlign_Left)
				[
					SAssignNew(RadioButtons[1], SCheckBox)
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
				+ SUniformGridPanel::Slot(1, 2)
				.HAlign(HAlign_Left)
				[
					SAssignNew(RadioButtons[2], SCheckBox)
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
			// Slider
			+ SVerticalBox::Slot()
			[
				SAssignNew(Slider, SSlider)
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
			+ SVerticalBox::Slot()
			.Padding(ButtonPadding)
			[
				SNew(SButton)
				.OnClicked(this, &SSettingsMenuWidget::OnSaveClicked)
				.VAlign(VAlign_Center)
				.AddMetaData(FDriverMetaData::Id("SaveButton"))
				[
					SNew(STextBlock)
					.Font(ButtonTextStyle)
					.Text(LOCTEXT("SaveSettings", "Save"))
					.Justification(ETextJustify::Center)
					.AddMetaData(FDriverMetaData::Id("SaveButton_Text"))
				]
			]
		]
	];

	this->LoadSettings();
}

// Callback for checking a radio button.
void SSettingsMenuWidget::HandleRadioButtonCheckStateChanged(ECheckBoxState NewRadioState,
                                                             ERadioChoice RadioThatChanged)
{
	if (NewRadioState == ECheckBoxState::Checked)
	{
		CurrentRadioChoice = RadioThatChanged;
	}
}

ECheckBoxState SSettingsMenuWidget::HandleRadioButtonIsChecked(ERadioChoice ButtonId) const
{
	return (CurrentRadioChoice == ButtonId)
		       ? ECheckBoxState::Checked
		       : ECheckBoxState::Unchecked;
}

// Callback for selection changes in the STextComboBox
void SSettingsMenuWidget::HandleTextComboBoxSelectionChanged(TSharedPtr<FString> NewSelection,
                                                             ESelectInfo::Type SelectInfo)
{
	TextComboBoxSelectedItem = NewSelection;
	// some logic
}

FReply SSettingsMenuWidget::OnBackClicked()
{
	if (OwningHUD.IsValid())
	{
		OwningHUD->HideSettingsMenu();
		OwningHUD->ShowMainMenu();
	}

	return FReply::Handled();
}

FReply SSettingsMenuWidget::OnSaveClicked()
{
	SaveSettings();

	return FReply::Handled();
}

void SSettingsMenuWidget::SaveSettings()
{
	if (USaveSettings* SaveSettingsInstance = Cast<USaveSettings>(
		UGameplayStatics::CreateSaveGameObject(USaveSettings::StaticClass())))
	{
		// Set up the (optional) delegate. It will be called after save
		FAsyncSaveGameToSlotDelegate SavedDelegate;
		// USomeUObjectClass::SaveGameDelegateFunction is a void function that takes the following parameters: const FString& SlotName, const int32 UserIndex, bool bSuccess
		SavedDelegate.BindRaw(this, &SSettingsMenuWidget::LogSaveSettings);

		// Set data on the savegame object.
		SaveSettingsInstance->SaveSlotName = SaveSlotName;
		// Text field
		SaveSettingsInstance->EditableTextBoxValue = EditableTextBox.Get()->GetText();
		// Text combo box
		SaveSettingsInstance->TextComboBoxValue = *TextComboBoxSelectedItem.Get();
		// Checkboxes
		for (int i = 0; i < CheckBoxes.Num(); i++)
		{
			SaveSettingsInstance->CheckBoxesState.Add(CheckBoxes[i].Get()->IsChecked());
		}
		// Radio buttons
		for (int i = 0; i < RadioButtons.Num(); i++)
		{
			SaveSettingsInstance->RadioButtonsState.Add(RadioButtons[i].Get()->IsChecked());
		}
		// Slider
		SaveSettingsInstance->SliderValue = Slider.Get()->GetValue();

		// Start async save process
		UGameplayStatics::AsyncSaveGameToSlot(SaveSettingsInstance, SaveSlotName, 0, SavedDelegate);
	}
}

void SSettingsMenuWidget::LogSaveSettings(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	UE_LOG(LogTemp, Warning, TEXT("SETTINGS DATA HAS BEEN SAVED: '%hhd' IN SLOT: '%s'"), bSuccess, *SlotName)
}

void SSettingsMenuWidget::LoadSettings()
{
	// Set up the delegate (obligatory)
	FAsyncLoadGameFromSlotDelegate LoadedDelegate;
	// USomeUObjectClass::LoadGameDelegateFunction is a void function that takes the following parameters: const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData
	LoadedDelegate.BindRaw(this, &SSettingsMenuWidget::ApplySettings);
	// Start async load process
	UGameplayStatics::AsyncLoadGameFromSlot(SaveSlotName, 0, LoadedDelegate);
}

void SSettingsMenuWidget::ApplySettings(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
	if (USaveSettings* LoadedSettings = Cast<USaveSettings>(LoadedGameData))
	{
		UE_LOG(LogTemp, Warning, TEXT("SAVED DATA HAS BEEN LOADED FROM SLOT: %s"), *SlotName);
		// Set text field value
		EditableTextBox.Get()->SetText(LoadedSettings->EditableTextBoxValue);
		// Set text combo box option
		if (!LoadedSettings->TextComboBoxValue.IsEmpty())
		{
			for (int i = 0; i < TextComboBoxOptions.Num(); i++)
			{
				if (*TextComboBoxOptions[i].Get() == LoadedSettings->TextComboBoxValue)
				{
					TextComboBoxSelectedItem = TextComboBoxOptions[i];
					break;
				}
			}
			TextComboBox.Get()->SetSelectedItem(TextComboBoxSelectedItem);
		}
		// Set checkboxes state
		if (LoadedSettings->CheckBoxesState.IsValidIndex(CheckBoxes.Num() - 1))
		{
			for (int i = 0; i < CheckBoxes.Num(); i++)
			{
				CheckBoxes[i].Get()->SetIsChecked(LoadedSettings->CheckBoxesState[i]);
			}
		}
		// Set radiobutton choice
		if (LoadedSettings->RadioButtonsState.IsValidIndex(RadioButtons.Num() - 1))
		{
			for (int i = 0; i < RadioButtons.Num(); i++)
			{
				if (LoadedSettings->RadioButtonsState[i])
				{
					CurrentRadioChoice = static_cast<ERadioChoice>(i);
				}
			}
		}
		// Set slider value
		Slider.Get()->SetValue(LoadedSettings->SliderValue);
	}
}

#undef LOCTEXT_NAMESPACE
