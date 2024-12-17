// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.h"
#include "Consumable.generated.h"

/**
 * 
 */
UCLASS()
class BEERSANDBRAWLS_API UConsumable : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float HealAmount = 25.0f;
};
