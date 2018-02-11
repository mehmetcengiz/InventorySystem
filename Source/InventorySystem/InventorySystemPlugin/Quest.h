// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "Engine/Texture2D.h"
#include "Engine/DataTable.h"
#include "Quest.generated.h"

UENUM(BlueprintType)
enum class EQuestStatus : uint8 {
	ACTIVE		UMETA(DisplayName = "Active"),
	FINISHED	UMETA(DisplayName = "Finished"),
	FAILED		UMETA(DisplayName = "Failed")
};

USTRUCT(BlueprintType)
struct FQuest {

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	TEnumAsByte<EQuestStatus>QuestStatus;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Details")
	FText QuestDetail;

};

