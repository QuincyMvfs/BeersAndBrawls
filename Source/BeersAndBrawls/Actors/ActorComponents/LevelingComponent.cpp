// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelingComponent.h"

#include "BeersAndBrawls/BeersAndBrawlsGameInstance.h"

// Sets default values for this component's properties
ULevelingComponent::ULevelingComponent()
{
	
}


// Called when the game starts
void ULevelingComponent::BeginPlay()
{
	Super::BeginPlay();
	GameInstanceRef = Cast<UBeersAndBrawlsGameInstance>(GetWorld()->GetGameInstance());
}

void ULevelingComponent::AddExp(int AmountToAdd)
{
	M_CurrentExp += AmountToAdd;
	
	if (GameInstanceRef)
	{
		GameInstanceRef->UpdatePlayerExp(M_CurrentExp);
	}
}

