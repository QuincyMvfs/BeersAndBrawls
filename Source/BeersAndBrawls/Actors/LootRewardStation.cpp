// Fill out your copyright notice in the Description page of Project Settings.


#include "LootRewardStation.h"

// Sets default values
ALootRewardStation::ALootRewardStation()
{
	SC_WinnerPodiumLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Winner Podium Location"));
	SC_LoserPodiumLocation = CreateDefaultSubobject<USceneComponent>(TEXT("Loser Podium Location"));
}

// Called when the game starts or when spawned
void ALootRewardStation::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALootRewardStation::GenerateRewards(UEnemyInfo* EnemyInfo)
{
	
}

