// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Texture2D.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TEnumAsByte<EItemType> ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TSubclassOf<UTexture2D> Image;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	bool bCombinable;


};