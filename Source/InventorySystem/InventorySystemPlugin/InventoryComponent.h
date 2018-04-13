// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySystemPlugin/Item.h"
#include "InventoryComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent {
GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UInventoryComponent();
	// Called every frame
	void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable,Category="Inventory")
	TArray<FItem> GetInventoryItems() { return InventoryItems; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	int32 GetInventorySize() { return InventorySize; }

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void PickUpItem(AActor* ActorToPickUP);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	bool AddItemToInventory(FItem Item);

protected:
	// Called when the game starts
	void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category = "Inventory")
	TArray<FItem> InventoryItems;
	
	UPROPERTY(BlueprintReadWrite,Category = "Inventory")
	TArray<bool> InventorySlotInfo;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 InventorySize = 20;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, Category = "Inventory")
	int32 MaxItemCountPerSlot = 9999;

public:
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SwapItemSlots(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetItemSlot(FItem Item, int32 NewSlot);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SplitItem(FItem ItemToSplit, int32 SplitQuantity, int32 NewSlot);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void CombineItems(FItem ItemA, FItem ItemB);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void DropItemFromInventory(FItem Item);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SplitAndDropItem(FItem ItemToSplit, int32 SplitQuantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SpawnItem(FItem Item) const;



private:
	void CreateSlotInfo();
	void DisableSlotByInventoryItems();

	UFUNCTION()
	void DeleteFromInventoryItems(FItem ItemToDelete);

};
