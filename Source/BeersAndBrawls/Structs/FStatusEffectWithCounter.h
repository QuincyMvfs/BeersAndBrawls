// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FStatusEffect.h"
#include "FStatusEffectWithCounter.generated.h"

USTRUCT(BlueprintType)
struct FStatusEffectWithCounter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FStatusEffect StatusEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Counter = 5;
};
