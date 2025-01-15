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
}

void UCurrencyComponent::AddBeerBux(int AmountToAdd)
{
	M_TotalBeerBux += AmountToAdd;
	FMath::Clamp(M_TotalBeerBux, 0, M_MaxBeerBux);
	
	OnBeerBuxAddedEvent.Broadcast(AmountToAdd);
}

void UCurrencyComponent::RemoveBeerBux(int AmountToRemove)
{
	M_TotalBeerBux -= AmountToRemove;
	FMath::Clamp(M_TotalBeerBux, 0, M_MaxBeerBux);

	OnBeerBuxRemovedEvent.Broadcast(AmountToRemove);
}


