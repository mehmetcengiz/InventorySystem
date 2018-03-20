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

	UFUNCTION(BlueprintCallable,Category="Inventory Items")
	TArray<FItem> GetInventoryItems() { return InventoryItems; }

	UFUNCTION(BlueprintCallable, Category = "Inventory Items")
	int32 GetInventorySize() { return InventorySize; }


protected:
	// Called when the game starts
	void BeginPlay() override;

	UPROPERTY(EditAnywhere,Category = "Inventory Items")
	TArray<FItem> InventoryItems;

	UPROPERTY(EditAnywhere, Category = "Inventory Items")
	int32 InventorySize = 20;

public:
	
	UFUNCTION(BlueprintCallable, Category = "Inventory Items")
	void SwapItemSlots(FItem DraggedItem, FItem DroppedTo);

	UFUNCTION(BlueprintCallable, Category = "Inventory Items")
	void SetItemSlot(FItem Item, int32 NewSlot);
	
	UFUNCTION(BlueprintCallable, Category = "Inventory Items")
	void SplitItem(FItem ItemToSplit, int32 SplitQuantity, int32 NewSlot);
};
