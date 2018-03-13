// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryWidget.generated.h"

struct FItem;
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

	UPROPERTY(BlueprintReadWrite, Category = "Inventory Component")
	class UInventoryComponent* InventoryComponent;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UButton* BtnTrash;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UWrapBox* WBoxInventory;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory Stlye")
	UTexture2D* DefaultImage;

private:
	void GetCharacterInventoryComponentRef();
	void CreateItemSlots();
	void RefreshInventory();
	void SwapItemsBySlot(FItem DraggedItem, FItem DroppedTo);
	void ChangeItemSlot(FItem Item, int32 Index);
};
