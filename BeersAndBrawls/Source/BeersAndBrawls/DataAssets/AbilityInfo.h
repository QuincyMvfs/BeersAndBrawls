// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AbilityInfo.generated.h"

class UAbilityPattern;

UCLASS(BlueprintType)
class BEERSANDBRAWLS_API UAbilityInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText M_AbilityName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText M_AbilityDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float M_StatMultiplier = 1.0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool M_IsUnlocked;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* M_AbilityIcon;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAbilityPattern* M_ItemPatterns;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UAnimMontage* M_Animation;
};
