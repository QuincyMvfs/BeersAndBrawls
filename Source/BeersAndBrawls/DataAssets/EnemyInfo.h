// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "Engine/DataAsset.h"
#include "EnemyInfo.generated.h"

struct FEnemyInfoStruct;
class UWeapon;
class UAbilityInfo;
/**
 * 
 */
UCLASS(BlueprintType)
class BEERSANDBRAWLS_API UEnemyInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FEnemyInfoStruct EnemyInfoStruct;
};
