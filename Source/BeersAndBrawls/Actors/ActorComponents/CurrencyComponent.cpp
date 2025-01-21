// Fill out your copyright notice in the Description page of Project Settings.


#include "CurrencyComponent.h"

// Sets default values for this component's properties
UCurrencyComponent::UCurrencyComponent()
{
	
}


// Called when the game starts
void UCurrencyComponent::BeginPlay()
{
	Super::BeginPlay();
	GameInstanceRef = Cast<UBeersAndBrawlsGameInstance>(GetWorld()->GetGameInstance());
}

void UCurrencyComponent::AddBeerBux(int AmountToAdd)
{
	M_TotalBeerBux += AmountToAdd;
	M_TotalBeerBux = FMath::Clamp(M_TotalBeerBux, 0, M_MaxBeerBux);
	
	GameInstanceRef->UpdatePlayerBeerBux(M_TotalBeerBux);
	
	OnBeerBuxAddedEvent.Broadcast(AmountToAdd);
}

void UCurrencyComponent::RemoveBeerBux(int AmountToRemove)
{
	M_TotalBeerBux -= AmountToRemove;
	M_TotalBeerBux = FMath::Clamp(M_TotalBeerBux, 0, M_MaxBeerBux);

	GameInstanceRef->UpdatePlayerExp(M_TotalBeerBux);

	OnBeerBuxRemovedEvent.Broadcast(AmountToRemove);
}


