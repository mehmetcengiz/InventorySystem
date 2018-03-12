// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryWidget.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "GameFramework/Character.h"

#include "ItemWidget.h"
#include "InventorySystemPlugin/InventoryComponent.h"
#include "InventorySystemPlugin/Item.h"


UInventoryWidget::UInventoryWidget(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer) {
	ConstructorHelpers::FClassFinder<UUserWidget> InventoryItemBPClass(TEXT("/Game/InventorySystem/MIKUI/SubWidgets/Inventory/WBP_Item"));
	if (!ensure(InventoryItemBPClass.Class != nullptr)) return;
	InventoryItemClass = InventoryItemBPClass.Class;
}

bool UInventoryWidget::Initialize() {

	//UE_LOG(LogTemp, Warning, TEXT("I initializeddd!!!!"));
	return false;
}

void UInventoryWidget::NativeConstruct() {
	GetCharacterInventoryComponentRef();
	CreateItemSlots();
	RefreshInventory();
}

void UInventoryWidget::GetCharacterInventoryComponentRef() {
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!ensure(PlayerCharacter != NULL)) return;

	InventoryComponent = PlayerCharacter->FindComponentByClass<UInventoryComponent>();
	if (!ensure(InventoryComponent != NULL)) return;

}

void UInventoryWidget::CreateItemSlots() {

	UWorld* World = this->GetWorld();
	if (!ensure(World != NULL)) return;

	if (!ensure(InventoryComponent != NULL)) return;
	int32 InventorySize = InventoryComponent->GetInventorySize();
	
	for (int32 i = 0; i < InventorySize; i++){
		UItemWidget* ItemWidget = CreateWidget<UItemWidget>(World,InventoryItemClass);
		if (!ensure(ItemWidget != NULL)) return;
	
		InventoryItemWidgets.Add(ItemWidget);
		WBoxInventory->AddChild(ItemWidget);

		//TODO ItemWidget->SetSlotIndex(i);
		//TODO ItemWidget->SetInventoryRef(this);
	}
}

void UInventoryWidget::RefreshInventory() {
	//Clean inventory widgets.
	for (auto item_widget : InventoryItemWidgets) {
		//TODO item_widget->SetIsSlotHasItem(false);
		FItem Item;
		Item.ItemName = FText::GetEmpty();
		Item.ItemType = EItemType::NONE;
		//TODO Item.Image 
		Item.Quantity = 0;
		Item.bCombinable = false;
		Item.SlotIndex = -1;	
		//TODO item_widget->SetItem(Item);
	}

	if (!ensure(InventoryComponent != NULL)) return;
	TArray<FItem> CurrentInventoryItems = InventoryComponent->GetInventoryItems();

	for (FItem inventory_item : CurrentInventoryItems) {
		UItemWidget* Item_widget = InventoryItemWidgets[inventory_item.SlotIndex];
		//TODO Item_widget->SetItem(inventory_item);
		//TODO Item_widget->SetIsSlotHasItem(true);

	}

}

void UInventoryWidget::SwapItemsBySlot() {
	
}

void UInventoryWidget::ChangeItemSlot() {
	
}

void UInventoryWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) {
	
}