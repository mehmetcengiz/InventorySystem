// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemWidget.h"

#include "Styling/SlateBrush.h"
#include "UObject/ConstructorHelpers.h"

#include "QuantitySpliterWidget.h"
#include "InventoryWidget.h"

bool UItemWidget::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	return true;
}

void UItemWidget::SetItem(FItem ItemInfoToSet) {
	//Set Item Info
	ItemInfo = ItemInfoToSet;

	//Set Quantitiy Text
	if(ItemInfo.bCombinable) {
		TxtQuantity->SetText(FText::FromString(FString::FromInt(ItemInfo.Quantity)));
	}else {
		TxtQuantity->SetText(FText::GetEmpty());
	}

	//Set Image Style
	ImgItem->Brush.SetResourceObject(ItemInfo.Image);
}

void UItemWidget::SetItemStyleAsDragged() {
	FSlateBrush slateBrush = ImgItem->Brush;	
	FSlateColor newTintColor = FSlateColor(DraggedColour);
	slateBrush.TintColor = newTintColor;

	ImgItem->SetBrush(slateBrush);
}

void UItemWidget::SetItemStyleAsDefault() {
	FSlateBrush slateBrush = ImgItem->Brush;
	FSlateColor newTintColor = FSlateColor(DefaultColour);
	slateBrush.TintColor = newTintColor;

	ImgItem->SetBrush(slateBrush);
}

void UItemWidget::OnItemDrop(UItemWidget* DroppedItem) {
	if (SlotIndex == DroppedItem->ItemInfo.SlotIndex) {	return;	}

	DroppedItem->bIsItemDragging = false;

	if(bIsSlotHasItem) {
		if(ItemInfo.ItemName.EqualTo(DroppedItem->ItemInfo.ItemName)) {
			//Combine
			InventoryWidgetRef->CombineItems(ItemInfo, DroppedItem->ItemInfo);
		}else {
			//Swap
			InventoryWidgetRef->SwapItemsBySlot(DroppedItem->ItemInfo, ItemInfo);
		}
	}else {
		if(InventoryWidgetRef->GetSplitFunctinalityEnabled() && DroppedItem->ItemInfo.bCombinable) {
			//Open split Item
			OpenSplitItemPanel(DroppedItem);
		}else {
			//Change Item Slot
			InventoryWidgetRef->ChangeItemSlot(DroppedItem->ItemInfo, SlotIndex);
		}
	}
}

void UItemWidget::OpenSplitItemPanel(UItemWidget* DroppedItem) {
		
	Spliter = InventoryWidgetRef->GetQuantitySpliterWidget();
	if (!ensure(Spliter != NULL)) return;	

	Spliter->InitializeSpliter(InventoryWidgetRef, DroppedItem->ItemInfo,SlotIndex);
	Spliter->AddToViewport(1);
}

