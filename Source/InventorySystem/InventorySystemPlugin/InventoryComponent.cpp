// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

#include "GameFramework/Actor.h"

#include "InventorySystemPlugin/ItemClasses/PickableItemComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UInventoryComponent::BeginPlay() {
	Super::BeginPlay();

	CreateSlotInfo();
	DisableSlotByInventoryItems();

}

// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                        FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UInventoryComponent::PickUpItem(AActor* ActorToPickUP) {
	auto ActorPickUpComponent = ActorToPickUP->FindComponentByClass(UPickableItemComponent::StaticClass());
	if(ActorPickUpComponent != NULL) {
		UE_LOG(LogTemp, Warning, TEXT("Lootable"));
		UPickableItemComponent* pickable_item = Cast<UPickableItemComponent>(ActorPickUpComponent);
		AddItemToInventory(pickable_item->ItemInformation);
		ActorToPickUP->Destroy();		
	}
}

void UInventoryComponent::AddItemToInventory(FItem Item) {
	for (int i = 0; i<InventorySlotInfo.Num(); i++) {
		if (InventorySlotInfo[i] == false) {
			Item.SlotIndex = i;
			InventorySlotInfo[i] = true;
			InventoryItems.Add(Item);
			return;
		}
	}
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
			InventorySlotInfo[Item.SlotIndex] = false;
			break;
		}
	}

	//Set slot Item
	Item.SlotIndex = NewSlot;

	//Add item back.
	InventoryItems.Add(Item);
	InventorySlotInfo[Item.SlotIndex] = true;
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
			InventorySlotInfo[ItemToSplit.SlotIndex] = false;
			InventoryItems.RemoveAt(i);
		}
	}
	
	//Split item to new two Item.
	FItem SplitedItem = ItemToSplit;
	SplitedItem.Quantity = SplitQuantity;
	SplitedItem.SlotIndex = NewSlot;
	ItemToSplit.Quantity -= SplitQuantity;

	//Add items back.
	if (SplitedItem.Quantity >= 0) {
		InventoryItems.Add(SplitedItem);
		InventorySlotInfo[SplitedItem.SlotIndex] = true;
	}

	if (ItemToSplit.Quantity >= 0) {
		InventoryItems.Add(ItemToSplit);
		InventorySlotInfo[ItemToSplit.SlotIndex]= true;
	}

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
			InventorySlotInfo[ItemA.SlotIndex]= false;
		}else if(InventoryItems[i].SlotIndex == ItemB.SlotIndex) {
			InventoryItems.RemoveAt(i);
			i--;
			InventorySlotInfo[ItemB.SlotIndex]= false;
		}
	}

	//Combine and Add items back.
	if((ItemA.Quantity + ItemB.Quantity) <= MaxItemCountPerSlot) {
		ItemA.Quantity += ItemB.Quantity;
		InventoryItems.Add(ItemA);
		InventorySlotInfo[ItemA.SlotIndex] = true;
	}else {
		ItemB.Quantity = ((ItemB.Quantity + ItemA.Quantity) - MaxItemCountPerSlot);
		ItemA.Quantity = MaxItemCountPerSlot;
		InventoryItems.Add(ItemA);
		InventoryItems.Add(ItemB);

		InventorySlotInfo[ItemA.SlotIndex] = true;
		InventorySlotInfo[ItemB.SlotIndex] = true;
	}

}

void UInventoryComponent::CreateSlotInfo() {
	for (int i = 0; i < InventorySize; i++) {		
		InventorySlotInfo.Add(false);
	}
}

void UInventoryComponent::DisableSlotByInventoryItems() {
	for (auto item : InventoryItems) {
		InventorySlotInfo[item.SlotIndex] = true;
	}
}


