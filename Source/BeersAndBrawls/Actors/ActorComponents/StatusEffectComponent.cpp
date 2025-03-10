// Fill out your copyright notice in the Description page of Project Settings.


#include "StatusEffectComponent.h"

// Sets default values for this component's properties
UStatusEffectComponent::UStatusEffectComponent()
{
	
}


// Called when the game starts
void UStatusEffectComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UStatusEffectComponent::TriggerStatusEffect(TArray<EStatusEffectTypes> StatusEffects, EActiveUser Instigator)
{
	for (const EStatusEffectTypes StatusEffect : StatusEffects)
	{
		switch (StatusEffect)
		{
			case EStatusEffectTypes::Dazed:
				break;
			case EStatusEffectTypes::Electrocuted:
				break;
			case EStatusEffectTypes::Frozen:
				break;
			case EStatusEffectTypes::Inflamed:
				break;
			case EStatusEffectTypes::Intoxicated:
				break;
			case EStatusEffectTypes::Invigorated:
				break;
			case EStatusEffectTypes::Weakened:
				break;
		}
	}

	return false;
}

