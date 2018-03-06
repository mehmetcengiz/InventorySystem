// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UInventoryComponent::BeginPlay() {
	Super::BeginPlay();

	

}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UInventoryComponent::SwapItemSlots(FItem DraggedItem, FItem DroppedTo) {
	//Delete current items.
	for (int32 i = 0; i < InventoryItems.Num(); i++) {
		if(InventoryItems[i].SlotIndex == DraggedItem.SlotIndex) {
			InventoryItems.RemoveAt(i);
		}
		if(InventoryItems[i].SlotIndex == DroppedTo.SlotIndex) {
			InventoryItems.RemoveAt(i);
		}
	}

	//Swap item slot.
	int32 BufferSlotIndex = DraggedItem.SlotIndex;
	DraggedItem.SlotIndex = DroppedTo.SlotIndex;
	DroppedTo.SlotIndex = BufferSlotIndex;

	//Add items back.
	InventoryItems.Add(DraggedItem);
	InventoryItems.Add(DroppedTo);
	
}

void UInventoryComponent::SetItemSlot(FItem Item, int32 NewSlot) {
	//Delete current item.
	for (int32 i = 0; i < InventoryItems.Num(); i++) {
		if (InventoryItems[i].SlotIndex == Item.SlotIndex) {
			InventoryItems.RemoveAt(i);
		}
	}

	//Set slot Item
	Item.SlotIndex = NewSlot;

	//Add item back.
	InventoryItems.Add(Item);
}
