// Fill out your copyright notice in the Description page of Project Settings.

#include "PickableItemComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UPickableItemComponent::UPickableItemComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UPickableItemComponent::BeginPlay() {
	Super::BeginPlay();
	AActor* Owner = GetOwner();
	if (!ensure(Owner != NULL)) return;
	auto SMesh = Cast<UStaticMeshComponent>(Owner->FindComponentByClass(UStaticMeshComponent::StaticClass()));
	if (!ensure(SMesh != NULL)) return;
	SMesh->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	//SMesh->Collision
}


// Called every frame
void UPickableItemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                           FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
