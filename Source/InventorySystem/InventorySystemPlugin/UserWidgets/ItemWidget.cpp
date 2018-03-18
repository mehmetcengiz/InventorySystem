// Fill out your copyright notice in the Description page of Project Settings.

#include "ItemWidget.h"

#include "Styling/SlateBrush.h"


void UItemWidget::SetItem(FItem ItemInfoToSet) {
	//Set Item Info
	ItemInfo = ItemInfoToSet;

	//Set Quantitiy Text
	if(ItemInfo.bCombinable) {
		TxtQuantity->SetText(FText::AsNumber(ItemInfo.Quantity));
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