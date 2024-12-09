// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilityPattern.generated.h"

struct FCombatPatterns;
/**
 * 
 */
UCLASS(BlueprintType)
class BEERSANDBRAWLS_API UAbilityPattern : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FCombatPatterns> CombatPatterns;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FCombatPatterns> CounterPatterns;
};
