#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Blueprint/UserWidget.h"

UCLASS(Abstract)
class UIInventoryEntry : public UUserWidget, public IUserObjectListEntry
{
private:
 GENERATED_BODY()

protected:
 virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
 
 UPROPERTY(meta=(BindWidget))
 class UTextBlock* NameLabel;

 UPROPERTY(meta=(BindWidget))
 class UImage* IconImage;
 
};
