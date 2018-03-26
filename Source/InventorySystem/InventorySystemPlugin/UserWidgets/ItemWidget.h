// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "InventorySystemPlugin/Item.h"

#include "ItemWidget.generated.h"

class UInventoryWidget;
class UQuantitySpliterWidget;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetItem(FItem ItemInfoToSet);
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")//TODO Merge with SetStyleDefault function
	void SetItemStyleAsDragged();

	UFUNCTION(BlueprintCallable, Category = "Item Setters")//TODO Merge with SetStyleDragged function
	void SetItemStyleAsDefault();

	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetQuantity(FText QuantityToSet) { TxtQuantity->SetText(QuantityToSet); }
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetSlotIndex(int32 SlotIndexToSet) { SlotIndex = SlotIndexToSet; }
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetIsSlotHasItem(bool bBoolToSet) { bIsSlotHasItem = bBoolToSet; }
	
	UFUNCTION(BlueprintCallable, Category = "Item Setters")
	void SetInventoryWidgetRef(UInventoryWidget* InventoryWidgetRefToSet) { InventoryWidgetRef = InventoryWidgetRefToSet; }

protected:

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UImage* ImgItem;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	UTextBlock* TxtQuantity;
	
	UPROPERTY(BlueprintReadWrite)
	FItem ItemInfo;
	
	UPROPERTY(BlueprintReadWrite)
	int32 SlotIndex;

	UPROPERTY(BlueprintReadWrite)
	bool bIsSlotHasItem;

	UPROPERTY(BlueprintReadWrite)
	bool bIsItemDragging;

	UPROPERTY(BlueprintReadWrite)
	UInventoryWidget* InventoryWidgetRef;
	
	UPROPERTY(BlueprintReadWrite)
	UQuantitySpliterWidget* Spliter;

	UPROPERTY(EditDefaultsOnly, Category = "DragDrop")
	FLinearColor DraggedColour = FLinearColor(0.026042, 0.026042, 0.026042, 0.729);

	UPROPERTY(EditDefaultsOnly, Category = "DragDrop")
	FLinearColor DefaultColour = FLinearColor(0.026042, 0.026042, 0.026042, 0);

	UFUNCTION(BlueprintCallable,Category="DragDrop")
	void OnItemDrop(UItemWidget* DroppedItem);
	
	UFUNCTION(BlueprintCallable,Category="DragDrop")
	void OpenSplitItemPanel(UItemWidget* DroppedItem);
	
};
