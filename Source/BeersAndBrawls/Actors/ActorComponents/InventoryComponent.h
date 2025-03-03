// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


class UConsumable;
class ABeersAndBrawlsCharacter;
class UWeapon;
class UItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnNewItemEquipped, UItem*, NewItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemAdded, UItem*, NewItem);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemRemoved, UItem*, NewItem);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnItemAdded OnItemAddedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnItemRemoved OnItemRemovedEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnNewItemEquipped OnNewItemEquippedEvent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeapon* M_SelectedWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UConsumable* M_SelectedConsumable;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UItem*> M_Items;

	UPROPERTY(EditDefaultsOnly, Instanced)
	UWeapon* M_DefaultSelectedWeapon;

	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<UItem*> M_DefaultItems;

	UFUNCTION(BlueprintCallable)
	void EquipWeapon(UItem* WeaponToEquip);

	UFUNCTION(BlueprintCallable)
	void EquipConsumable(UItem* ConsumableToEquip);

	UFUNCTION(BlueprintCallable)
	void AddItem(UItem* ItemToAdd);

	UFUNCTION(BlueprintCallable)
	void RemoveItem(UItem* ItemToRemove);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool DoesPlayerHaveItem(UItem* ItemToCheck);

	bool CanPlayerSellWeapon();

	bool CanPlayerSellConsumable();

	ABeersAndBrawlsCharacter* PlayerRef;
		
};
