// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Item.generated.h"

USTRUCT(BlueprintType)
struct FItemType : public FTableRowBase {
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Type")
	FText ItemType;
};

USTRUCT(BlueprintType)
struct FItem{
	
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TSubclassOf<FItemType> ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TSubclassOf<UTexture2D> Image;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	bool bCombinable;


};

USTRUCT(BlueprintType)
struct FItemList : public FTableRowBase {
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory Data")
	FItem ItemList;


};