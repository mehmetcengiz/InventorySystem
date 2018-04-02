// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityMenuWidget.h"

#include "Components/Button.h"


UUtilityMenuWidget::UUtilityMenuWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
	
}

bool UUtilityMenuWidget::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) { return false; }

	if (!ensure(BtnBestiary != NULL)) return false;
	if (!ensure(BtnCrafting != NULL)) return false;
	if (!ensure(BtnInventory != NULL)) return false;
	if (!ensure(BtnMainMenu != NULL)) return false;
	if (!ensure(BtnMap != NULL)) return false;
	if (!ensure(BtnOptions != NULL)) return false;
	if (!ensure(BtnQuest != NULL)) return false;

	BtnBestiary->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnBestiaryOnClicked);
	BtnCrafting->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnCraftingOnClicked);
	BtnInventory->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnInventoryOnClicked);
	BtnMainMenu->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnMainMenuOnClicked);
	BtnMap->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnMapOnClicked);
	BtnOptions->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnOptionsOnClicked);
	BtnQuest->OnClicked.AddDynamic(this, &UUtilityMenuWidget::BtnQuestOnClicked);

	return true;
}

void UUtilityMenuWidget::BtnBestiaryOnClicked() {
	UE_LOG(LogTemp,Warning,TEXT("Bestiary Pressed !!!"));
}

void UUtilityMenuWidget::BtnCraftingOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("Crafting Pressed !!!"));
}

void UUtilityMenuWidget::BtnInventoryOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("Inventory Pressed !!!"));
}

void UUtilityMenuWidget::BtnMainMenuOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("MainMenu Pressed !!!"));
}

void UUtilityMenuWidget::BtnMapOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("Map Pressed !!!"));
}

void UUtilityMenuWidget::BtnOptionsOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("Options Pressed !!!"));
}

void UUtilityMenuWidget::BtnQuestOnClicked() {

	UE_LOG(LogTemp, Warning, TEXT("Quest Pressed !!!"));
}

