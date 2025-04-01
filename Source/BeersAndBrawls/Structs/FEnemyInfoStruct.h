// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EAbilitySpeeds.h"
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
	int EnemyLevel;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float MaxHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int BeerBuxReward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int ExpReward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAbilitySpeeds AttackSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAbilitySpeeds CounterSpeed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float AttackSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float CounterSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UWeapon* EquippedWeapon;
};
