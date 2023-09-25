#include "UIInventoryEntry.h"

#include "UIInventoryItem.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


void UIInventoryEntry::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	UIInventoryItem* Item = Cast<UIInventoryItem>(ListItemObject);
	NameLabel->SetText(Item->DisplayName);
	// IconImage->SetBrushFromTexture(Item->Icon);
}

