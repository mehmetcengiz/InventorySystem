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


	UFUNCTION(BlueprintCallable,Category="DragDrop")
	void SwapItemsBySlot(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable,Category="DragDrop")
	void CombineItems(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable, Category = "DragDrop")
	void ChangeItemSlot(FItem Item, int32 NewSlot);

	UFUNCTION(BlueprintCallable, Category = "DragDrop")
	void SplitItem(FItem Item, int32 SplitQuantity, int32 NewSlot);
	
	/*Getter Setters*/
	UFUNCTION(BlueprintCallable, Category = "Getter Setter")
	void SetSplitFunctionalityEnabled(bool BoolToSet) { bIsSplitFunctionalityEnabled = BoolToSet; }

	UFUNCTION(BlueprintCallable,Category = "Getter Setter")
	bool GetSplitFunctinalityEnabled() const { return bIsSplitFunctionalityEnabled; }

	UFUNCTION(BlueprintCallable, Category = "Getter Setter")
	void SetItemSpliter(UQuantitySpliterWidget* SpliterRef) { Spliter = SpliterRef; }

	UFUNCTION(BlueprintCallable,Category = "Getter Setter")
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
	void RefreshInventory();

};
