// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.h"
#include "Weapon.generated.h"

/**
 * 
 */
UCLASS()
class BEERSANDBRAWLS_API UWeapon : public UItem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float BaseDamage;
};
