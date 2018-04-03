// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"

#include "../InventorySystem/InventorySystemPlugin/Item.h"

#include "PickableItemComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORYSYSTEM_API UPickableItemComponent : public UActorComponent
{
GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPickableItemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite)
	UBoxComponent* PickUpTrigger = nullptr;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Inventory Items")
	FItem ItemInformation;
	
};
