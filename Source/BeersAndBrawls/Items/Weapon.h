// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.h"
#include "BeersAndBrawls/Enums/EAbilitySpeeds.h"
#include "BeersAndBrawls/Enums/EComboComplexity.h"
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
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EAbilitySpeeds AverageSpeed = EAbilitySpeeds::Average;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EComboComplexity WeaponComplexity = EComboComplexity::Average;
};
