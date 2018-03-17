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
