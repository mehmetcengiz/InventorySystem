// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
//Engine Created headers.
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

//User Created headers.
#include "InventorySystemPlugin/Item.h"

#include "QuantitySpliterWidget.generated.h"


/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UQuantitySpliterWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	bool Initialize() override;
	void InitializeSpliter(class UInventoryWidget* InventoryWidgetRefToSet, FItem InventoryItem, int32 DroppedSlotIndex);

protected:
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UEditableTextBox* SplitQuantity;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class USlider* SliderCount;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnSplitAccept;
	
private:
	UFUNCTION()
	void ConfirmQuantitySplit();
	
	UPROPERTY()
	class UInventoryWidget* InventoryWidgetRef;

	UPROPERTY()
	FItem CurrentItemInfo;

	UPROPERTY()
	int32 DropItemSlot;
	
};
