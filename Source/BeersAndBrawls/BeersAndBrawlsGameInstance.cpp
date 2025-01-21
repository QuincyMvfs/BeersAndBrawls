// Fill out your copyright notice in the Description page of Project Settings.


#include "BeersAndBrawlsGameInstance.h"

#include "Kismet/GameplayStatics.h"

void UBeersAndBrawlsGameInstance::UpdatePlayerBeerBux(int NewValue)
{
	M_PlayerBeerBux = NewValue;
	OnUpdatePlayerBeerBuxEvent.Broadcast(NewValue);
}

void UBeersAndBrawlsGameInstance::UpdatePlayerExp(int NewValue)
{
	M_PlayerExp = NewValue;
	OnUpdatePlayerExpEvent.Broadcast(NewValue);
}
