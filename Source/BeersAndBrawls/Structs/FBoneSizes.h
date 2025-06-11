// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FBoneSizes.generated.h"

USTRUCT(BlueprintType)
struct FBoneSizes
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector HeadSize = FVector::One();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector ChestSize = FVector::One();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector ArmSize = FVector::One();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector HandSize = FVector::One();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector LegSize = FVector::One();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	FVector FeetSize = FVector::One();
	
};
