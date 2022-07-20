﻿#pragma once

#include "CoreMinimal.h"
#include "SlateBasics.h"
#include "Widgets/Input/STextComboPopup.h"

class SSettingsMenuWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSettingsMenuWidget)
		{
		}

		SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnBackClicked();

	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; }

private:

	// Holds the combo box in the STextComboBox example.
	TSharedPtr<STextComboBox> TextComboBox;
	
	// Radio button options
	enum ERadioChoice
	{
		Radio0,
		Radio1,
		Radio2,
	};

	// Store current radio button choice
	ERadioChoice CurrentRadioChoice;

	// Callback for checking a radio button.
	void HandleRadioButtonCheckStateChanged(ECheckBoxState NewRadioState, ERadioChoice RadioThatChanged)
	{
		if (NewRadioState == ECheckBoxState::Checked)
		{
			CurrentRadioChoice = RadioThatChanged;
		}
	}

	// Callback for determining whether a radio button is checked.
	ECheckBoxState HandleRadioButtonIsChecked(ERadioChoice ButtonId) const
	{
		return (CurrentRadioChoice == ButtonId)
			       ? ECheckBoxState::Checked
			       : ECheckBoxState::Unchecked;
	}

	// Callback for selection changes in the STextComboBox
	void HandleTextComboBoxSelectionChanged (TSharedPtr<FString> NewSelection, ESelectInfo::Type SelectInfo)
	{
		
	}
};
