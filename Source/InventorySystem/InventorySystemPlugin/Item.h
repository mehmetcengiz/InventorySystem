// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.generated.h"

UENUM(BlueprintType)
enum EItemType{
	ITEMTYPE_QUEST	UMETA(DisplayName = "Quest Item"),
	ITEMTYPE_ARMOR	UMETA(DisplayName = "Armor"),
	ITEMTYPE_WEAPON	UMETA(DisplayName = "Weapon")
};

USTRUCT(BlueprintType)
struct FItem{
	
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	TEnumAsByte<EItemType> ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Struct")
	bool bCombinable;


};