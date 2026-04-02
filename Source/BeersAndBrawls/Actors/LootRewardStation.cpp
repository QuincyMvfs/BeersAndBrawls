// Fill out your copyright notice in the Description page of Project Settings.


#include "LootRewardStation.h"

#include "BeersAndBrawls/DataAssets/EnemyInfo.h"

// Sets default values
ALootRewardStation::ALootRewardStation()
{
	
}

// Called when the game starts or when spawned
void ALootRewardStation::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALootRewardStation::GenerateRewards(FEnemyInfoStruct EnemyInfo, FText& OutEnemyName, FText& OutEnemyDesc,
	int& OutEnemyLevel, int& OutBeerBuxReward, int& OutExperienceReward, FLootInfo& OutLootInfo)
{
	OutEnemyName = EnemyInfo.EnemyName;
	OutEnemyDesc = EnemyInfo.EnemyDescription;
	OutEnemyLevel = EnemyInfo.EnemyLevel;
	OutBeerBuxReward = EnemyInfo.BeerBuxReward;
	OutExperienceReward = EnemyInfo.ExpReward;
	OutLootInfo = EnemyInfo.LootInfo;
}


