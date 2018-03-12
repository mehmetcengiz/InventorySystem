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
	virtual void NativeConstruct() override;

	void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;

	TSubclassOf<class UItemWidget> InventoryItemClass;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory Component")
	TArray<UItemWidget*> InventoryItemWidgets;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UButton* BtnTrash;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UWrapBox* WBoxInventory;
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory Component")
	class UInventoryComponent* InventoryComponent;

private:
	void GetCharacterInventoryComponentRef();
	void CreateItemSlots();
	void RefreshInventory();
	void SwapItemsBySlot();
	void ChangeItemSlot();
};
