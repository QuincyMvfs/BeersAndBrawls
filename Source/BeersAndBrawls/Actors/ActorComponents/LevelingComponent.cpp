// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelingComponent.h"

#include "InventoryComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/BeersAndBrawlsGameInstance.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/Items/Consumable.h"
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
	
	bool HasLeveledUp = false;
	
	for (int i = M_CurrentLevel; i < M_ExpRequiredPerLevel.Num(); i++)
	{
		if (i > M_ExpRequiredPerLevel.Num()) break;
		
		if (M_CurrentExp >= M_ExpRequiredPerLevel[i])
		{
			M_CurrentLevel++;
			M_SkillPoints++;
			HasLeveledUp = true;
		}
	}
	
	if (HasLeveledUp)
	{
		OnLevelUpEvent.Broadcast();
	}
	
	OnExperienceGainedEvent.Broadcast();
	
	if (GameInstanceRef)
	{
		GameInstanceRef->UpdatePlayerExp(M_CurrentExp);
	}
}

int ULevelingComponent::GetPreviousLevel(int ExpToRemove)
{
	int PreviousLevel = 1;
	int PreviousExp = M_CurrentExp - ExpToRemove;
	for (int i = 0; i < M_ExpRequiredPerLevel.Num() - 1; i++)
	{
		if (PreviousExp >= M_ExpRequiredPerLevel[i] && PreviousExp <= M_ExpRequiredPerLevel[i + 1])
		{
			PreviousLevel = i;
			break;
		}
	}
	
	if (PreviousExp < M_ExpRequiredPerLevel[0])
	{
		PreviousLevel = 0;
	}
	
	return PreviousLevel;
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

	if (PlayerRef->InventoryComponent->M_SelectedConsumable)
	{
		if (PlayerRef->InventoryComponent->M_SelectedConsumable->Abilities.Num() > 0)
		{
			for (UAbilityInfo* Ability : PlayerRef->InventoryComponent->M_SelectedConsumable->Abilities)
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

