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
	M_RemainingInputs = M_SelectedCombatPattern.KeyInputs;
	M_CanReceiveInputs = true;
	OnCombatPatternReceived.Broadcast(M_SelectedCombatPattern);
}

void UCombatComponent::ReceiveInput(ECombatKey InputKey)
{
	if (!M_CanReceiveInputs) return;

	if (InputKey == M_RemainingInputs[0])
	{
		OnCorrectInputGiven.Broadcast(InputKey);
		M_RemainingInputs.RemoveAt(0);
		UE_LOG(LogTemp, Warning, TEXT("Correct Input Received"));
		if (M_RemainingInputs.Num() <= 0)
		{
			M_CanReceiveInputs = false;
			UE_LOG(LogTemp, Warning, TEXT("Pattern Completed"));
			OnCombatPatternCompleted.Broadcast();
		}
	}
	else if (InputKey != M_RemainingInputs[0])
	{
		UE_LOG(LogTemp, Warning, TEXT("FAIL Input Received"));
		OnFailInputGiven.Broadcast(InputKey);
	}
}
