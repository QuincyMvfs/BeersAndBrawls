// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectComponent.h"

#include "BeersAndBrawls/Enums/EUpgradeType.h"
#include "BeersAndBrawls/Structs/FStatusEffectWithCounter.h"

// Sets default values for this component's properties
UStatusEffectComponent::UStatusEffectComponent()
{
	FStatusEffectWithCounter StatusEffect;
	StatusEffect.StatusEffect.EffectType = EStatusEffectTypes::Dazed;
	StatusEffect.StatusEffect.EffectTier = 2;
	StatusEffect.Counter = 3;
	ActiveStatusEffects.Add(StatusEffect);
}


// Called when the game starts
void UStatusEffectComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UStatusEffectComponent::TriggerStatusEffect(TArray<FStatusEffect> StatusEffects,
	UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	for (const FStatusEffect StatusEffect : StatusEffects)
	{
		switch (StatusEffect.EffectType)
		{
			case EStatusEffectTypes::Dazed:
				Trigger_Daze(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Electrocuted:
				Trigger_Electrocute(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Frozen:
				Trigger_Frozen(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Inflamed:
				Trigger_Inflamed(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Intoxicated:
				Trigger_Intoxicated(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Invigorated:
				Trigger_Invigorated(StatusEffect.EffectTier, Instigator, Victim);
				break;
			case EStatusEffectTypes::Weakened:
				Trigger_Weaken(StatusEffect.EffectTier, Instigator, Victim);
				break;
		}
	}

	return false;
}

bool UStatusEffectComponent::Trigger_Daze(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Electrocute(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Inflamed(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Frozen(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Intoxicated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Weaken(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

bool UStatusEffectComponent::Trigger_Invigorated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim)
{
	return false;
}

