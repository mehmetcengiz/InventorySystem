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
			i--;
		}else if (InventoryItems[i].SlotIndex == DroppedTo.SlotIndex) {
			InventoryItems.RemoveAt(i);
			i--;
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
	//Conditions to NOT SET.
	for (int32 i = 0; i < InventoryItems.Num(); i++) {
		if (InventoryItems[i].SlotIndex == NewSlot) { return; }
	}

	//Delete current item.
	for (int32 i = 0; i < InventoryItems.Num(); i++) {
		if (InventoryItems[i].SlotIndex == Item.SlotIndex) {
			InventoryItems.RemoveAt(i);
			break;
		}
	}

	//Set slot Item
	Item.SlotIndex = NewSlot;

	//Add item back.
	InventoryItems.Add(Item);
}

void UInventoryComponent::SplitItem(FItem ItemToSplit, int32 SplitQuantity, int32 NewSlot) {
	
	//Conditions to NOT SPLIT
	if(!ItemToSplit.bCombinable) return;
	if(SplitQuantity <= 0 ) return;
	for (int32 i = 0; i < InventoryItems.Num(); i++) {
		if(InventoryItems[i].SlotIndex == NewSlot) return;
	}

	//Delete Splited Item.
	for(int32 i = 0; i<InventoryItems.Num(); i++) {
		if(InventoryItems[i].SlotIndex == ItemToSplit.SlotIndex) {
			InventoryItems.RemoveAt(i);
		}
	}
	
	//Split item to new two Item.
	FItem SplitedItem = ItemToSplit;
	SplitedItem.Quantity = SplitQuantity;
	SplitedItem.SlotIndex = NewSlot;
	ItemToSplit.Quantity -= SplitQuantity;

	//Add items back.
	if(SplitedItem.Quantity >=0)	InventoryItems.Add(SplitedItem);
	if (ItemToSplit.Quantity >= 0)	InventoryItems.Add(ItemToSplit);
}

void UInventoryComponent::CombineItems(FItem ItemA, FItem ItemB) {
	//Conditions to NOT COMBINE.
	if (!(ItemA.ItemName.EqualTo(ItemB.ItemName))) return;
	if (!ItemA.bCombinable && !ItemB.bCombinable) return;

	//Delete Combined Items
	for (int32 i = 0; i<InventoryItems.Num(); i++) {
		if (InventoryItems[i].SlotIndex == ItemA.SlotIndex) {
			InventoryItems.RemoveAt(i);
			i--;
		}else if(InventoryItems[i].SlotIndex == ItemB.SlotIndex) {
			InventoryItems.RemoveAt(i);
			i--;
		}
	}

	//Combine and Add items back.
	if((ItemA.Quantity + ItemB.Quantity) <= MaxItemCountPerSlot) {
		ItemA.Quantity += ItemB.Quantity;
		InventoryItems.Add(ItemA);
	}else {
		ItemB.Quantity = ((ItemB.Quantity + ItemA.Quantity) - MaxItemCountPerSlot);
		ItemA.Quantity = MaxItemCountPerSlot;
		InventoryItems.Add(ItemA);
		InventoryItems.Add(ItemB);
	}

}


