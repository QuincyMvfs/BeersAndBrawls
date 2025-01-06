// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BeersAndBrawlsGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class BEERSANDBRAWLS_API UBeersAndBrawlsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float M_PlayerExp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	float M_PlayerBeerBux;
};
