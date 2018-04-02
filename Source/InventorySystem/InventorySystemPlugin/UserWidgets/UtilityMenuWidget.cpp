// Fill out your copyright notice in the Description page of Project Settings.

#include "UtilityMenuWidget.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"


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
	if (UtilityPageSwitcher == NULL) { return; }
	if (MenuHeader == NULL) { return; }
	if (BestiaryPage == NULL) { return; }

	UtilityPageSwitcher->SetActiveWidget(BestiaryPage);
	MenuHeader->SetText(FText::FromString("Bestiary"));
}

void UUtilityMenuWidget::BtnCraftingOnClicked() {
	if (UtilityPageSwitcher == NULL) { return; }
	if (MenuHeader == NULL) { return; }
	if (CraftingPage == NULL) { return; }

	UtilityPageSwitcher->SetActiveWidget(CraftingPage);
	MenuHeader->SetText(FText::FromString("Crafting"));
}

void UUtilityMenuWidget::BtnInventoryOnClicked() {
	if (UtilityPageSwitcher == NULL) { return; }
	if (MenuHeader == NULL) { return; }
	if (InventoryPage == NULL) { return; }

	UtilityPageSwitcher->SetActiveWidget(InventoryPage);
	MenuHeader->SetText(FText::FromString("Inventory"));
}

void UUtilityMenuWidget::BtnMainMenuOnClicked() {
	//TODO Implement Main Menu button clicked.
}

void UUtilityMenuWidget::BtnMapOnClicked() {
	if (UtilityPageSwitcher == NULL) { return; }
	if (MenuHeader == NULL) { return; }
	if (MapPage == NULL) { return; }

	UtilityPageSwitcher->SetActiveWidget(MapPage);
	MenuHeader->SetText(FText::FromString("Map"));
}

void UUtilityMenuWidget::BtnOptionsOnClicked() {
	//TODO Implement Options button clicked.
}

void UUtilityMenuWidget::BtnQuestOnClicked() {
	if (UtilityPageSwitcher == NULL) { return; }
	if (MenuHeader == NULL) { return; }
	if (QuestPage == NULL) { return; }

	UtilityPageSwitcher->SetActiveWidget(QuestPage);
	MenuHeader->SetText(FText::FromString("Quests"));
}

