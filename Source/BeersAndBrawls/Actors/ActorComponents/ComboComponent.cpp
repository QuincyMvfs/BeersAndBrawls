// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboComponent.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"


// Sets default values for this component's properties
UComboComponent::UComboComponent()
{
	
}


// Called when the game starts
void UComboComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UComboComponent::InitiateCombo(UAbilityInfo* Ability, FCombatPatterns CombatPattern)
{
	M_SelectedAbility = Ability;
	M_SelectedCombatPattern = CombatPattern;
	
	// Sets the Abilities Damage Multiplier Base
	M_BaseMultiplier = M_SelectedAbility->M_StatMultiplier;
	
	// Gets the total # of pattern segments in the CombatPattern
	float SquareRoot = FMath::Sqrt(static_cast<float>(CombatPattern.KeyInputs.Num()));
	int TotalPatternSegments = FMath::FloorToInt(SquareRoot);
	
	// How much to increase the CurrentComboMultiplier each time the combo is increased
	M_ComboIncreaseInterval = M_BaseMultiplier / TotalPatternSegments;
	M_CurrentComboMultiplier = M_ComboIncreaseInterval;
	
	// Sets the minimum combo multiplier to half of the base multiplier
	M_MinimumComboMultiplier = M_BaseMultiplier/ TotalPatternSegments;
	
	OnComboInitiatedEvent.Broadcast();
}

void UComboComponent::UpdateCombo()
{
	M_ComboStreak++;
	M_CurrentComboMultiplier += M_ComboIncreaseInterval;
	
	OnComboUpdatedEvent.Broadcast(M_ComboStreak, M_CurrentComboMultiplier);
}

void UComboComponent::ResetCombo()
{
	M_ComboStreak = 0;
	M_CurrentComboMultiplier = M_MinimumComboMultiplier;
	
	OnComboUpdatedEvent.Broadcast(M_ComboStreak, M_CurrentComboMultiplier);
}
