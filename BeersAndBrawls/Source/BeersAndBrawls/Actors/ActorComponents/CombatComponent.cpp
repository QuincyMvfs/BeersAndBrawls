// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UCombatComponent::SetCombatPattern(FCombatPatterns NewCombatPattern)
{
	M_SelectedCombatPattern = NewCombatPattern;
	M_CanReceiveInputs = true;
}