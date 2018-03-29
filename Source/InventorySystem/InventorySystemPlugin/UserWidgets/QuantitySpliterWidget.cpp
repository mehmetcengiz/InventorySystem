// Fill out your copyright notice in the Description page of Project Settings.

#include "QuantitySpliterWidget.h"

#include "InventorySystemPlugin/UserWidgets/InventoryWidget.h"

#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "Components/Slider.h"

bool UQuantitySpliterWidget::Initialize() {
	bool Succes = Super::Initialize();
	if (!Succes) { return false; }

	if (!ensure(BtnSplitAccept != NULL)) return false;
	BtnSplitAccept->OnClicked.AddDynamic(this, &UQuantitySpliterWidget::ConfirmQuantitySplit);

	return true;
}

void UQuantitySpliterWidget::InitializeSpliter(UInventoryWidget* InventoryWidgetRefToSet, const FItem ItemInfo, const int32 DroppedSlotIndex) {
	SplitQuantity->SetText(FText::AsNumber(ItemInfo.Quantity/2));
	InventoryWidgetRef = InventoryWidgetRefToSet;
	CurrentItemInfo = ItemInfo;
	DropItemSlot = DroppedSlotIndex;
}

void UQuantitySpliterWidget::ConfirmQuantitySplit() {
	
	FString newQuantatiyString = SplitQuantity->GetText().ToString();

	while(newQuantatiyString.Contains(",")) {
		int32 index = newQuantatiyString.Find(",");
		newQuantatiyString.RemoveAt(index);
	}

	int32 newQuantatiy = FCString::Atoi(*newQuantatiyString);
	
	if (!ensure(InventoryWidgetRef != NULL)) return;
	InventoryWidgetRef->SplitItem(CurrentItemInfo, newQuantatiy, DropItemSlot);
	
	RemoveFromParent();
}
