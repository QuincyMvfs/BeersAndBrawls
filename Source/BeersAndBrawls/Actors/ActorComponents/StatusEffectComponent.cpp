// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectComponent.h"

#include "HealthComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Actors/Enemy.h"
#include "BeersAndBrawls/Enums/EUpgradeType.h"
#include "BeersAndBrawls/Structs/FStatusEffectWithCounter.h"

// Sets default values for this component's properties
UStatusEffectComponent::UStatusEffectComponent()
{
	if (ABeersAndBrawlsCharacter* PlayerRef = Cast<ABeersAndBrawlsCharacter>(GetOwner()))
	{
		ParentHealthComponent = PlayerRef->HealthComponent;
		ParentCombatComponent = PlayerRef->CombatComponent;
	}
	else if (AEnemy* EnemyRef = Cast<AEnemy>(GetOwner()))
	{
		ParentHealthComponent = EnemyRef->HealthComponent;
		ParentCombatComponent = EnemyRef->CombatComponent;
	}
}


// Called when the game starts
void UStatusEffectComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UStatusEffectComponent::TriggerStatusEffect(TArray<FStatusEffect> StatusEffects,
	UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("%d Status Effects"), StatusEffects.Num());
	if (StatusEffects.Num() == 0) return;

	for (FStatusEffectWithCounter M_Effect : ActiveStatusEffectsWithCounter)
	{
		for (int i = 0; i < StatusEffects.Num(); i++)
		{
			// int M_Effect_Int = static_cast<int>(M_Effect.StatusEffect.EffectTier);
			// int Effect_Int = static_cast<int>(StatusEffects[i].EffectTier);
			
			if (M_Effect.StatusEffect.EffectTier == StatusEffects[i].EffectTier)
			{
				StatusEffects.RemoveAt(i);
				break;
			}
		}
	}
	
	if (StatusEffects.Num() == 0) return;
	
	for (const FStatusEffect StatusEffect : StatusEffects)
	{
		// If the given effect lands successfully
		if (DoesEffectLand(StatusEffect))
		{
			FStatusEffectWithCounter StatusEffectWithCounter;
			StatusEffectWithCounter.StatusEffect = StatusEffect;
			int EffectTier = StatusEffect.EffectTier-1;
				
			switch (StatusEffect.EffectType)
			{
				case EStatusEffectTypes::Dazed:
					StatusEffectWithCounter.Counter = Dazed_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Electrocuted:
					StatusEffectWithCounter.Counter = Electrocuted_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Frozen:
					StatusEffectWithCounter.Counter = Frozen_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Inflamed:
					StatusEffectWithCounter.Counter = Inflamed_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Intoxicated:
					StatusEffectWithCounter.Counter = Intoxicated_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Invigorated:
					StatusEffectWithCounter.Counter = Invigorated_EffectDuration[EffectTier];
					break;
				case EStatusEffectTypes::Weakened:
					StatusEffectWithCounter.Counter = Weakened_EffectDuration[EffectTier];
					break;
			}

			ActiveStatusEffectsWithCounter.Add(StatusEffectWithCounter);
			
			OnEffectTriggeredEvent.Broadcast(StatusEffectWithCounter);
		}
	}
}

void UStatusEffectComponent::ActivateStatusEffects()
{
	if (ActiveStatusEffectsWithCounter.Num() == 0) return;

	for (int i = 0; i < ActiveStatusEffectsWithCounter.Num(); i++)
	{
		int EffectTier = ActiveStatusEffectsWithCounter[i].StatusEffect.EffectTier;
		switch (ActiveStatusEffectsWithCounter[i].StatusEffect.EffectType)
		{
			case EStatusEffectTypes::Dazed:
				Trigger_Daze(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Electrocuted:
				Trigger_Electrocute(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Frozen:
				Trigger_Frozen(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Inflamed:
				Trigger_Inflamed(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Intoxicated:
				Trigger_Intoxicated(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Invigorated:
				Trigger_Invigorated(EffectTier, this, this);
				break;
			case EStatusEffectTypes::Weakened:
				Trigger_Weaken(EffectTier, this, this);
				break;
		}

		ActiveStatusEffectsWithCounter[i].Counter--;
		OnEffectUsedEvent.Broadcast(ActiveStatusEffectsWithCounter[i]);

		if (ActiveStatusEffectsWithCounter[i].Counter <= 0)
		{
			OnEffectEndedEvent.Broadcast(ActiveStatusEffectsWithCounter[i]);
			ActiveStatusEffectsWithCounter.RemoveAt(i);
			return;
		}
	}
}

bool UStatusEffectComponent::DoesEffectLand(FStatusEffect StatusEffect)
{
	float ChanceToTrigger = 0.0f;
	int EffectTier = StatusEffect.EffectTier-1;
	
	switch (StatusEffect.EffectType)
	{
		case EStatusEffectTypes::Dazed:
			ChanceToTrigger = Dazed_ChanceToTrigger[EffectTier];
			break;
		case EStatusEffectTypes::Electrocuted:
			ChanceToTrigger = Electrocuted_ChanceToTrigger[EffectTier];
			break;
		case EStatusEffectTypes::Frozen:
			ChanceToTrigger = Frozen_ChanceToTrigger[EffectTier];
			break;
		case EStatusEffectTypes::Inflamed:
			ChanceToTrigger = Inflamed_ChanceToTrigger[EffectTier];
			break;
		case EStatusEffectTypes::Intoxicated:
			ChanceToTrigger = 1.0f;
			break;
		case EStatusEffectTypes::Invigorated:
			ChanceToTrigger = 1.0f;
			break;
		case EStatusEffectTypes::Weakened:
			ChanceToTrigger = Weakened_ChanceToTrigger[EffectTier];
			break;
		default:
			ChanceToTrigger = 0.0f;
			break;
	}

	if (ChanceToTrigger <= 0.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("ChanceToTrigger is 0"));
		return false;
	}
	if (ChanceToTrigger >= 1.0f)
	{
		UE_LOG(LogTemp, Warning, TEXT("ChanceToTrigger is 100"));
		return false;
	}

	// If the value rolled if higher than the chance to trigger, then the effect failed
	ChanceToTrigger *= 100.0f;
	int RandFloat = FMath::RandRange(0, 100);
	if (RandFloat > ChanceToTrigger)
	{
		UE_LOG(LogTemp, Warning, TEXT("SE FAILED | Needed below %f / Had %d"), ChanceToTrigger, RandFloat);
		return false;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("SE SUCCEEDED | Needed below %f / Had %d"), ChanceToTrigger, RandFloat);
		return true;
	}

}


bool UStatusEffectComponent::Trigger_Daze(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Daze"));
	return false;
}

bool UStatusEffectComponent::Trigger_Electrocute(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Electrocute"));
	return false;
}

bool UStatusEffectComponent::Trigger_Inflamed(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	if (ParentHealthComponent)
	{
		float DamageToDeal = ParentHealthComponent->M_MaxHealth * Inflamed_DamagePercent[EffectTier-1];
		ParentHealthComponent->TakeDamage(DamageToDeal, this->GetOwner(), this->GetOwner());
	}
	
	UE_LOG(LogTemp, Display, TEXT("Trigger_Inflamed"));
	return false;
}

bool UStatusEffectComponent::Trigger_Frozen(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Frozen"));
	return false;
}

bool UStatusEffectComponent::Trigger_Intoxicated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Intoxicated"));
	return false;
}

bool UStatusEffectComponent::Trigger_Weaken(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Weaken"));
	return false;
}

bool UStatusEffectComponent::Trigger_Invigorated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	UE_LOG(LogTemp, Warning, TEXT("Trigger_Invigorated"));
	return false;
}

