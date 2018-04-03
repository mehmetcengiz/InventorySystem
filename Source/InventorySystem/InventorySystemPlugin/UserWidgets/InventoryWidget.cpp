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
#include "QuantitySpliterWidget.h"


UInventoryWidget::UInventoryWidget(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer) {
	ConstructorHelpers::FClassFinder<UUserWidget> InventoryItemBPClass(TEXT("/Game/InventorySystem/MIKUI/SubWidgets/Inventory/WBP_Item"));
	if (!ensure(InventoryItemBPClass.Class != nullptr)) return;
	InventoryItemClass = InventoryItemBPClass.Class;
	
	ConstructorHelpers::FClassFinder<UUserWidget> QuantitySpliterBP(TEXT("/Game/InventorySystem/MIKUI/SubWidgets/Inventory/WBP_QuantitySpliter"));
	if (!ensure(QuantitySpliterBP.Class != nullptr)) return;
	QuantitySpliterClass = QuantitySpliterBP.Class;
}

void UInventoryWidget::RemoveFromParent() {
	if(Spliter != NULL) {
		Spliter->RemoveFromParent();
	}

	Super::RemoveFromParent();
}

bool UInventoryWidget::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(BtnTrash != NULL)) return false;
	if (!ensure(WBoxInventory != NULL)) return false;

	//TODO BtnTrash->OnClicked.AddDynamic(this, &UInventoryWidget::ThrowItemToTrash);
	return false;
}

void UInventoryWidget::NativeConstruct() {
	Super::NativeConstruct();
	GetCharacterInventoryComponentRef();
	CreateItemSpliter();
	CreateItemSlots();
	RefreshInventory();
}

void UInventoryWidget::GetCharacterInventoryComponentRef() {
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!ensure(PlayerCharacter != NULL)) return;

	InventoryComponent = PlayerCharacter->FindComponentByClass<UInventoryComponent>();
	if (!ensure(InventoryComponent != NULL)) return;

}

void UInventoryWidget::CreateItemSpliter() {
	UWorld* World = GetWorld();
	if (!ensure(World != NULL)) return;
	Spliter = CreateWidget<UQuantitySpliterWidget>(World, QuantitySpliterClass);
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

		ItemWidget->SetSlotIndex(i);
		ItemWidget->SetInventoryWidgetRef(this);
	}
}

void UInventoryWidget::RefreshInventory() {
	//Clean inventory widgets.
	for (auto item_widget : InventoryItemWidgets) {
		item_widget->SetIsSlotHasItem(false);
		FItem Item;
		Item.ItemName = FText::GetEmpty();
		Item.ItemType = EItemType::NONE;
		Item.Image = DefaultImage;
		Item.Quantity = 0;
		Item.bCombinable = false;
		Item.SlotIndex = -1;	
		item_widget->SetItem(Item);
	}

	if (!ensure(InventoryComponent != NULL)) return;
	TArray<FItem> CurrentInventoryItems = InventoryComponent->GetInventoryItems();

	for (FItem inventory_item : CurrentInventoryItems) {
		if (InventoryItemWidgets.Num() <= 0) { return; }
		UItemWidget* Item_widget = InventoryItemWidgets[inventory_item.SlotIndex];
		Item_widget->SetItem(inventory_item);
		Item_widget->SetIsSlotHasItem(true);
	}

}

void UInventoryWidget::SwapItemsBySlot(FItem DraggedItem, FItem DroppedTo) {
	if (!ensure(InventoryComponent != NULL)) return;
	InventoryComponent->SwapItemSlots(DraggedItem, DroppedTo);
	RefreshInventory();
}

void UInventoryWidget::CombineItems(FItem DraggedItem, FItem DroppedTo) {
	if (!ensure(InventoryComponent != NULL)) return;
	InventoryComponent->CombineItems(DraggedItem, DroppedTo);
	RefreshInventory();
}

void UInventoryWidget::ChangeItemSlot(FItem Item, int32 NewSlot) {
	if (!ensure(InventoryComponent != NULL)) return;
	InventoryComponent->SetItemSlot(Item, NewSlot);
	RefreshInventory();
}

void UInventoryWidget::SplitItem(FItem Item, int32 SplitQuantity, int32 NewSlot) {
	if (!ensure(InventoryComponent != NULL)) return;
	InventoryComponent->SplitItem(Item, SplitQuantity, NewSlot);
	RefreshInventory();
}
