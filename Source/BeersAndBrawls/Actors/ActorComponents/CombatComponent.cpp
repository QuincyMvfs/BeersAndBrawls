// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatComponent.h"
#include "StatusEffectComponent.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/DataAssets/AbilityPattern.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCombatComponent::GenerateRandomPatterns(UAbilityInfo* Ability, UCombatComponent* Victim)
{
	const FCombatPatterns NewCombatPattern = GenerateRandomCombatPattern(Ability);
	const FCombatPatterns NewCounterPattern = GenerateRandomCounterPattern(Ability, Victim);
	
	M_SelectedCombatPattern = NewCombatPattern;
	M_SelectedCounterPattern = NewCounterPattern;
}

FCombatPatterns UCombatComponent::GenerateRandomCombatPattern(UAbilityInfo* Ability)
{
	const int RandInt = Ability->M_ItemPatterns->CombatPatterns.Num() - 1;
	FCombatPatterns Pattern = FactorInDazedModifier(Ability->M_ItemPatterns->CombatPatterns[RandInt], M_Dazed_Modifier);
	
	return Pattern;
}

FCombatPatterns UCombatComponent::GenerateRandomCounterPattern(UAbilityInfo* Ability, UCombatComponent* Victim)
{
	const int RandInt = Ability->M_ItemPatterns->CounterPatterns.Num() - 1;
	FCombatPatterns Pattern = FactorInDazedModifier(Ability->M_ItemPatterns->CounterPatterns[RandInt], Victim->M_Dazed_Modifier);
	
	return Pattern;
}

void UCombatComponent::SetCombatPattern(FCombatPatterns NewCombatPattern)
{
	M_SelectedCombatPattern = NewCombatPattern;
	M_RemainingInputs = M_SelectedCombatPattern.KeyInputs;

	float SquareRoot = FMath::Sqrt(static_cast<float>(M_RemainingInputs.Num()));
	const int TotalPatterns = FMath::CeilToInt(SquareRoot);
	M_InputSegmentThreshold = TotalPatterns;
	for (int i = 0; i <= TotalPatterns; i++)
	{
		FCombatPatterns ActivePattern;
		int Index = TotalPatterns * i;
		for (int j = 0; j < TotalPatterns; j++)
		{
			if (M_RemainingInputs.Num() <= j + Index)
			{
				break;
			}
			
			ActivePattern.KeyInputs.Add(M_RemainingInputs[Index + j]);
		}
		
		M_ActiveRemainingSegments.Add(ActivePattern);
	}
	
	M_CanReceiveInputs = true;
	OnCombatPatternReceived.Broadcast(M_SelectedCombatPattern);

	if (M_IsElectrocuted) StartElectrocuting();
}

void UCombatComponent::ReceiveInput(ECombatKey InputKey)
{
	if (!M_CanReceiveInputs) return;

	if (InputKey == M_RemainingInputs[M_ActiveInputIndex])
	{
		OnCorrectInputGiven.Broadcast(InputKey);
		M_ActiveInputIndex++;
		
		if (M_RemainingInputs.Num() <= M_ActiveInputIndex)
		{
			M_CanReceiveInputs = false;
			OnCombatPatternCompleted.Broadcast();
		}
		else if (M_ActiveInputIndex >= M_InputSegmentThreshold)
		{
			M_ActiveSegmentIndex++;
			M_InputSegmentThreshold += M_ActiveRemainingSegments[0].KeyInputs.Num();
			OnCombatPatternSegmentCompleted.Broadcast(M_ActiveSegmentIndex);
		}
		
	}
	else if (InputKey != M_RemainingInputs[M_ActiveInputIndex])
	{
		M_ActiveInputIndex = 0;
		OnFailInputGiven.Broadcast(InputKey);
	}
}

void UCombatComponent::StopInputs()
{
	M_CanReceiveInputs = false;
	M_ActiveInputIndex = 0;
	M_ActiveSegmentIndex = 0;
	
	if (M_IsElectrocuted)
	{
		GetWorld()->GetTimerManager().ClearTimer(M_ElectrocuteLoopTimer);
		M_ElectrocuteLoopTimer.Invalidate();

		GetWorld()->GetTimerManager().ClearTimer(M_ElectrocuteTimer);
		M_ElectrocuteTimer.Invalidate();
		
		StopElectrocuting();

		M_IsElectrocuted = false;
	}

	M_Dazed_Modifier = 1.0f;
}

FCombatPatterns UCombatComponent::FactorInDazedModifier(FCombatPatterns Pattern, float Modifier)
{
	FCombatPatterns NewCombatPattern = Pattern;
	TArray<ECombatKey> TempKeys = Pattern.KeyInputs;
	int InputsToAdd = FMath::RoundToInt(NewCombatPattern.KeyInputs.Num() * Modifier);
	if (InputsToAdd > NewCombatPattern.KeyInputs.Num())
	{
		InputsToAdd = InputsToAdd - NewCombatPattern.KeyInputs.Num();
		if (InputsToAdd > 0)
		{
			int j = 0;
			for (int i = 0; i < InputsToAdd; i++)
			{
				if (!TempKeys.IsValidIndex(i))
				{
					TempKeys.Add(NewCombatPattern.KeyInputs[j]);
					j++;
				}
				
				NewCombatPattern.KeyInputs.Add(TempKeys[i]);
			}
		}
	}
	else if (InputsToAdd < NewCombatPattern.KeyInputs.Num())
	{
		for (int i = InputsToAdd; i > 0; i--)
		{
			NewCombatPattern.KeyInputs.RemoveAt(i);
		}
	}

	return NewCombatPattern;
}

void UCombatComponent::AdjustDazedModifier(float Amount)
{
	float NewModifier = M_Dazed_Modifier += Amount;
	M_Dazed_Modifier = FMath::Clamp(NewModifier, 0.1f, 3.0f);
}

void UCombatComponent::AdjustDamageModifier(float Amount)
{
	float NewModifier = M_Damage_Multiplier += Amount;
	M_Damage_Multiplier = FMath::Clamp(NewModifier, 0.1f, 3.0f);
}

void UCombatComponent::SetElectrocutionVariables(float InterruptionGap, float InterruptionTime, int EffectTier)
{
	M_IsElectrocuted = true;
	M_InterruptionGap = InterruptionGap;
	M_InterruptionDelay= InterruptionTime;
	M_ElectrocutionTier = EffectTier;
}

void UCombatComponent::StartElectrocuting()
{
	GetWorld()->GetTimerManager().ClearTimer(M_ElectrocuteLoopTimer);
	M_ElectrocuteLoopTimer.Invalidate();
	
	GetWorld()->GetTimerManager().SetTimer(M_ElectrocuteLoopTimer, this, &UCombatComponent::ElectrocutingLoop,
		M_InterruptionGap + M_InterruptionDelay, true );
}

void UCombatComponent::ElectrocutingLoop()
{
	GetWorld()->GetTimerManager().ClearTimer(M_ElectrocuteTimer);
	M_ElectrocuteTimer.Invalidate();
	
	OnElectrocutedEvent.Broadcast();
	M_CanReceiveInputs = false;
	
	GetWorld()->GetTimerManager().SetTimer(M_ElectrocuteTimer, this, &UCombatComponent::StopElectrocuting,
		M_InterruptionDelay, false);
}

void UCombatComponent::StopElectrocuting()
{
	M_CanReceiveInputs = true;
	OnElectrocuteEndedEvent.Broadcast();
}
