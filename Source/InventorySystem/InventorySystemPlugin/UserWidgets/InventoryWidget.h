// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UInventoryWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual bool Initialize() override;
	void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

private:

	TSubclassOf<class UUserWidget> InventoryItemClass;

	void GetCharacterInventoryRef();
	void CreateItemSlots();
	void RefreshInventory();
	void SwapItemsBySlot();
	void ChangeItemSlot();
	
	
};
