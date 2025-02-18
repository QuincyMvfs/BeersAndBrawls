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
	
	if (M_CurrentExp >= M_ExpRequiredPerLevel[M_CurrentLevel])
	{
		M_CurrentLevel++;
		M_SkillPoints++;
		OnLevelUpEvent.Broadcast();
	}
	
	OnExperienceGainedEvent.Broadcast();
	
	if (GameInstanceRef)
	{
		GameInstanceRef->UpdatePlayerExp(M_CurrentExp);
	}
}

void ULevelingComponent::GetLevelInfo(int& OutCurrentXP, int& XPNeeded, int& OutCurrentLevel, float& OutCurrentRatio)
{
	OutCurrentXP = M_CurrentExp;
	XPNeeded = M_ExpRequiredPerLevel[M_CurrentLevel];
	OutCurrentLevel = M_CurrentLevel;
	float CurrentXP = M_CurrentExp;
	float TotalXPNeeded = M_ExpRequiredPerLevel[M_CurrentLevel];
	OutCurrentRatio = CurrentXP / TotalXPNeeded;
}

