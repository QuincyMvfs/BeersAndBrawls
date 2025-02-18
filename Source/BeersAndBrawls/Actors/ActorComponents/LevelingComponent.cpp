// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelingComponent.h"

#include "InventoryComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/BeersAndBrawlsGameInstance.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

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

void ULevelingComponent::SpendSkillPoints(int Amount)
{
	M_SkillPoints -= Amount;
	OnSkillPointSpentEvent.Broadcast();
}

void ULevelingComponent::UpdateAllAbilities()
{
	if (!PlayerRef)
	{
		PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	}
	
	M_AllAbilities.Empty();

	if (PlayerRef->InventoryComponent->M_SelectedWeapon)
	{
		if (PlayerRef->InventoryComponent->M_SelectedWeapon->Abilities.Num() > 0)
		{
			for (UAbilityInfo* Ability : PlayerRef->InventoryComponent->M_SelectedWeapon->Abilities)
			{
				M_AllAbilities.Add(Ability);
			}
		}
	} 

	if (M_UnlockedAbilities.Num() > 0)
	{
		for (UAbilityInfo* Ability : M_UnlockedAbilities)
		{
			M_AllAbilities.Add(Ability);
		}
	}

	OnAbilitiesUpdatedEvent.Broadcast();
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

