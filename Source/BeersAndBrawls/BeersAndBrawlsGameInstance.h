// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BeersAndBrawlsGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePlayerBeerBux, int, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdatePlayerExp, int, NewValue);

UCLASS()
class BEERSANDBRAWLS_API UBeersAndBrawlsGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnUpdatePlayerBeerBux OnUpdatePlayerBeerBuxEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnUpdatePlayerExp OnUpdatePlayerExpEvent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int M_PlayerExp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
	int M_PlayerBeerBux;

	void UpdatePlayerBeerBux(int NewValue);
	
	void UpdatePlayerExp(int NewValue);

	
};
