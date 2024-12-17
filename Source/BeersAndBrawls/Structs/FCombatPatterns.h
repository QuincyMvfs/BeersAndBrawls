// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FCombatPatterns.generated.h"

enum class ECombatKey : uint8;

USTRUCT(BlueprintType)
struct FCombatPatterns
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<ECombatKey> KeyInputs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimeToComplete = 1.0f;
};
