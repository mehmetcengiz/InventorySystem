// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryWidget.h"

#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

#include "Components/Button.h"
#include "Components/WrapBox.h"
#include "GameFramework/Character.h"

#include "ItemWidget.h"
#include "InventorySystemPlugin/InventoryComponent.h"


UInventoryWidget::UInventoryWidget(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer) {
	ConstructorHelpers::FClassFinder<UUserWidget> InventoryItemBPClass(TEXT("/Game/InventorySystem/MIKUI/SubWidgets/Inventory/WBP_Item"));
	if (!ensure(InventoryItemBPClass.Class != nullptr)) return;
	InventoryItemClass = InventoryItemBPClass.Class;
}

bool UInventoryWidget::Initialize() {

	//UE_LOG(LogTemp, Warning, TEXT("I initializeddd!!!!"));
	return false;
}

void UInventoryWidget::NativeConstruct() {
	GetCharacterInventoryRef();
	CreateItemSlots();
	RefreshInventory();
}

void UInventoryWidget::OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) {
	
}

void UInventoryWidget::GetCharacterInventoryRef() {
	ACharacter* PlayerCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (!ensure(PlayerCharacter != NULL)) return;

	InventoryComponent = PlayerCharacter->FindComponentByClass<UInventoryComponent>();
	if (!ensure(InventoryComponent != NULL)) return;

}

void UInventoryWidget::CreateItemSlots() {
	
}

void UInventoryWidget::RefreshInventory() {
	
}

void UInventoryWidget::SwapItemsBySlot() {
	
}

void UInventoryWidget::ChangeItemSlot() {
	
}
