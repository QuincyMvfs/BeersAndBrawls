// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


class UWeapon;
class UItem;

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
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeapon* M_SelectedWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UItem*> M_Items;

	UPROPERTY(EditDefaultsOnly, Instanced)
	UWeapon* M_DefaultSelectedWeapon;

	UPROPERTY(EditDefaultsOnly, Instanced)
	TArray<UItem*> M_DefaultItems;
		
};
