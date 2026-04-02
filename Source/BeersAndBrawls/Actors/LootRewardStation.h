// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "BeersAndBrawls/Structs/FLootInfo.h"
#include "GameFramework/Actor.h"
#include "LootRewardStation.generated.h"

class UEnemyInfo;

UCLASS()
class BEERSANDBRAWLS_API ALootRewardStation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALootRewardStation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void GenerateRewards(FEnemyInfoStruct EnemyInfo, FText& OutEnemyName, FText& OutEnemyDesc, int& OutEnemyLevel, 
		int& OutBeerBuxReward, int& OutExperienceReward, FLootInfo& OutLootInfo);

};
