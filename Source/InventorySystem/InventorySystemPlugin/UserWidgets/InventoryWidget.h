// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySystemPlugin/Item.h"
#include "InventoryWidget.generated.h"

class UQuantitySpliterWidget;
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

	virtual void RemoveFromParent() override;

	UFUNCTION(BlueprintCallable,Category="InventoryWidget")
	void SwapItemsBySlot(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable,Category="InventoryWidget")
	void CombineItems(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void ChangeItemSlot(FItem Item, int32 NewSlot);

	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void SplitItem(FItem Item, int32 SplitQuantity, int32 NewSlot);
	
	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void RefreshInventory();
	
	/*Getter Setters*/
	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void SetSplitFunctionalityEnabled(bool BoolToSet) { bIsSplitFunctionalityEnabled = BoolToSet; }

	UFUNCTION(BlueprintCallable,Category = "InventoryWidget")
	bool GetSplitFunctinalityEnabled() const { return bIsSplitFunctionalityEnabled; }

	UFUNCTION(BlueprintCallable, Category = "InventoryWidget")
	void SetItemSpliter(UQuantitySpliterWidget* SpliterRef) { Spliter = SpliterRef; }

	UFUNCTION(BlueprintCallable,Category = "InventoryWidget")
	UQuantitySpliterWidget* GetQuantitySpliterWidget() const { return Spliter; }


protected:
	virtual bool Initialize() override;
	virtual void NativeConstruct() override;

	TSubclassOf<class UItemWidget> InventoryItemClass;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory Component")
	TArray<UItemWidget*> InventoryItemWidgets;

	UPROPERTY(BlueprintReadWrite, Category = "Inventory Component")
	class UInventoryComponent* InventoryComponent;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UButton* BtnTrash;

	UPROPERTY(meta = (BindWidget) , BlueprintReadWrite)
	class UWrapBox* WBoxInventory;
	
	UPROPERTY(EditDefaultsOnly, Category = "Inventory Style")
	UTexture2D* DefaultImage;
	
	UPROPERTY(BlueprintReadWrite, Category = "Inventory Functionality")
	bool bIsSplitFunctionalityEnabled;

	UPROPERTY(BlueprintReadWrite)
	UQuantitySpliterWidget* Spliter;

	TSubclassOf<class UUserWidget> QuantitySpliterClass;

private:
	void GetCharacterInventoryComponentRef();
	void CreateItemSpliter();
	void CreateItemSlots();


	

};
