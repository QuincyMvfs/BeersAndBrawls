// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnemyInfo.generated.h"

class UWeapon;
class UAbilityInfo;
/**
 * 
 */
UCLASS(BlueprintType)
class BEERSANDBRAWLS_API UEnemyInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText EnemyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText EnemyDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int BeerBuxReward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float ExpReward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float AttackSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CounterSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeapon* EquippedWeapon;
};
