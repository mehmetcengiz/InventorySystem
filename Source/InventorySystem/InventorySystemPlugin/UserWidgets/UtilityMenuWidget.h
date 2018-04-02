// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UtilityMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UUtilityMenuWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UUtilityMenuWidget(const FObjectInitializer& ObjectInitializer);
	
protected:
	virtual bool Initialize() override;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnBestiary;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnCrafting;
	
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnInventory;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnMainMenu;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnMap;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnOptions;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* BtnQuest;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidgetSwitcher* UtilityPageSwitcher;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UTextBlock* MenuHeader;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidget* BestiaryPage;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidget* CraftingPage;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidget* InventoryPage;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidget* MapPage;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UWidget* QuestPage;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Bestiary;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_BestiaryList;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Crafting;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Equipment;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Inventory;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Map;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_QuestDetail;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UUserWidget* WBP_Quests;

	UFUNCTION(BlueprintCallable,Category="Menu Selectors")
	void BtnBestiaryOnClicked();

	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnCraftingOnClicked();

	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnInventoryOnClicked();

	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnMainMenuOnClicked();
	
	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnMapOnClicked();

	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnOptionsOnClicked();

	UFUNCTION(BlueprintCallable, Category = "Menu Selectors")
	void BtnQuestOnClicked();

	
};
