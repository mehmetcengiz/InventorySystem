// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "InventorySystemPlugin/Item.h"


#include "ItemWidget.generated.h"

class UInventoryWidget;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTexture2D* ImgItem;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	FText TxtQuantity;
	
	UPROPERTY(BlueprintReadWrite)
	FItem ItemInfo;
	
	UPROPERTY(BlueprintReadWrite)
	int32 SlotIndex;

	UPROPERTY(BlueprintReadWrite)
	bool bIsSlotHasItem;

	UPROPERTY(BlueprintReadWrite)
	UInventoryWidget* InventoryWidgetRef;
	
};
