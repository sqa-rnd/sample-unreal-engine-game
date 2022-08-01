#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "Widgets/Input/STextComboPopup.h"
#include "Kismet/GameplayStatics.h"

class SSettingsMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsMenuWidget) {}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:
	// Slot name for settings file
	FString SaveSlotName = TEXT("Settings");
	
	// Hold editable text box element
	TSharedPtr<SEditableTextBox> EditableTextBox;
	
	// Hold text combo box element
	TSharedPtr<STextComboBox> TextComboBox;

	// Hold the text options for the STextComboBox
	TArray<TSharedPtr<FString>> TextComboBoxOptions;

	// Hold the selected item of the STextComboBox
	TSharedPtr<FString> TextComboBoxSelectedItem;

	// Hold list of checkbox elements
	TArray<TSharedPtr<SCheckBox>> CheckBoxes;

	// Hold list of radio button elements
	TArray<TSharedPtr<SCheckBox>> RadioButtons;

	// Hold slider element
	TSharedPtr<SSlider> Slider;
	
	// Radio button options
	enum ERadioChoice
	{
		Radio0,
		Radio1,
		Radio2,
	};

	// Store current radio button choice
	ERadioChoice CurrentRadioChoice;

	// Back button callback
	FReply OnBackClicked();

	// Save button callback
	FReply OnSaveClicked();

	// Save settings main method 
	void SaveSettings();

	// Callback for settings save
	void LogSaveSettings(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	// Load settings main method
	void LoadSettings();

	// Callback for load settings, applies values from save file to widgets
	void ApplySettings(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);

	// Callback for checking a radio button
	void HandleRadioButtonCheckStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioThatChanged);

	// Callback for determining whether a radio button is checked
	ECheckBoxState HandleRadioButtonIsChecked(ERadioChoice ButtonId) const;

	// Callback for selection changes in the STextComboBox
	void HandleTextComboBoxSelectionChanged (TSharedPtr<FString> NewSelection, ESelectInfo::Type SelectInfo);
};
