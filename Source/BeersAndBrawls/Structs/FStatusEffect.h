// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EStatusEffectTypes.h"
#include "FStatusEffect.generated.h"

enum class EStatusEffectTypes : uint8;

USTRUCT(BlueprintType)
struct FStatusEffect
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	EStatusEffectTypes EffectType = EStatusEffectTypes::Dazed;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (ClampMin = 0, ClampMax = 6, UIMin = 1, UIMax = 6))
	int EffectTier = 1;
};
