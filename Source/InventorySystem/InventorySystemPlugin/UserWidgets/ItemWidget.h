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
	
public:
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetImage(UTexture2D* ImgToSet) { ImgItem = ImgToSet; }

	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetQuantity(FText QuantityToSet) { TxtQuantity = QuantityToSet; }

	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetItemInfo(FItem ItemInfoToSet) { ItemInfo = ItemInfoToSet; }

	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetSlotIndex(int32 SlotIndexToSet) { SlotIndex = SlotIndexToSet; }
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetIsSlotHasItem(bool bBoolToSet) { bIsSlotHasItem = bBoolToSet; }
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetInventoryWidgetRef(UInventoryWidget* InventoryWidgetRefToSet) { InventoryWidgetRef = InventoryWidgetRefToSet; }

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
