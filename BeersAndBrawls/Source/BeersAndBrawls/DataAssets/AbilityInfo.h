// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilityInfo.generated.h"

class UAbilityPattern;

UCLASS()
class BEERSANDBRAWLS_API UAbilityInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText M_AbilityName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText M_AbilityDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool M_IsUnlocked;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAbilityPattern* M_ItemPatterns;
};
