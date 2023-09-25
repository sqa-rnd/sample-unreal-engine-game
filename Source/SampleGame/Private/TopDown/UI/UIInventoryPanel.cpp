// Fill out your copyright notice in the Description page of Project Settings.


#include "UIInventoryPanel.h"

#include "UIInventoryItem.h"
#include "Components/ListView.h"

void UIInventoryPanel::NativeConstruct()
{
	Super::NativeConstruct();

	UIInventoryItem(FText::FromString("Item 0"));
	UIInventoryItem(FText::FromString("Item 1"));
	UIInventoryItem(FText::FromString("Item 2"));
	
	TArray<UIInventoryItem*> Inventory;
	Inventory.Add(UIInventoryItem(FText::FromString("Item 0")));

	InventoryListView->SetListItems(Inventory);
}

