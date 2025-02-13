// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Shop.generated.h"

class ABeersAndBrawlsCharacter;
class UItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemBought, UItem*, PurchasedItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemSold, UItem*, SoldItem);

UCLASS()
class BEERSANDBRAWLS_API AShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnItemBought OnItemBoughtEvent;

	UPROPERTY(BlueprintAssignable)
	FOnItemSold OnItemSoldEvent;
	
	UFUNCTION(BlueprintCallable)
	bool BuyItem(UItem* ItemToBuy);

	UFUNCTION(BlueprintCallable)
	bool SellItem(UItem* ItemToSell);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanBuyItem(UItem* ItemToBuy);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanSellItem(UItem* ItemToSell);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, Category = "Items")
	TArray<UItem*> M_ItemsForSale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Items")
	TArray<UItem*> M_DefaultItemsForSale;

	ABeersAndBrawlsCharacter* PlayerRef;
};
