// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FEnemyInfoStruct.generated.h"

class UWeapon;

USTRUCT(BlueprintType)
struct FEnemyInfoStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText EnemyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText EnemyDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxHealth;

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
