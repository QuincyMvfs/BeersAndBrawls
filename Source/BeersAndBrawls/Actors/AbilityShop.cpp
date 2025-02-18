// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityShop.h"

#include "ActorComponents/HealthComponent.h"
#include "ActorComponents/LevelingComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Enums/EUpgradeType.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAbilityShop::AAbilityShop()
{

}

// Called when the game starts or when spawned
void AAbilityShop::BeginPlay()
{
	Super::BeginPlay();
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

bool AAbilityShop::UpgradeAbility(EUpgradeType UpgradeType, int SkillPoints)
{
	if (SkillPoints <= 0) return false;
	
	switch (UpgradeType)
	{
		case EUpgradeType::Blunt:
			PlayerRef->LevelingComponent->M_UnlockedAbilities.Add(M_BluntAbilitiesToBuy[M_BluntAbilitiesIndex]);
			M_BluntAbilitiesIndex++;
			return true;
		case EUpgradeType::Chop:
			PlayerRef->LevelingComponent->M_UnlockedAbilities.Add(M_ChopAbilitiesToBuy[M_ChopAbilitiesIndex]);
			M_ChopAbilitiesIndex++;
			return true;
		case EUpgradeType::Slash:
			PlayerRef->LevelingComponent->M_UnlockedAbilities.Add(M_SlashAbilitiesToBuy[M_SlashAbilitiesIndex]);
			M_SlashAbilitiesIndex++;
			return true;
		case EUpgradeType::Unarmed:
			PlayerRef->LevelingComponent->M_UnlockedAbilities.Add(M_UnarmedAbilitiesToBuy[M_UnarmedAbilitiesIndex]);
			M_UnarmedAbilitiesIndex++;
			break;
		case EUpgradeType::Health:
			PlayerRef->HealthComponent->LevelUpMaxHealth(M_HealthUpgradesToBuy[M_HealthUpgradeIndex]);
			return true;
		case EUpgradeType::Damage:
			PlayerRef->M_DamageMultiplier = M_DamageUpgradesToBuy[M_DamageUpgradeIndex];
			M_DamageUpgradeIndex++;
			return true;
		case EUpgradeType::Combat:
			PlayerRef->M_CombatSpeedMultiplier = M_CombatUpgradesToBuy[M_CombatUpgradeIndex];
			M_CombatUpgradeIndex++;
			return true;
		case EUpgradeType::Counter:
			PlayerRef->M_CounterSpeedMultiplier = M_CounterUpgradesToBuy[M_CounterUpgradeIndex];
			M_CounterUpgradeIndex++;
			return true;
	}

	return true;
}

