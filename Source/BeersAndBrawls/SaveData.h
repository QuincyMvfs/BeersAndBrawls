// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveData.generated.h"

/**
 * 
 */
UCLASS()
class BEERSANDBRAWLS_API USaveData : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int PlayerExp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int PlayerBeerBux;
};
