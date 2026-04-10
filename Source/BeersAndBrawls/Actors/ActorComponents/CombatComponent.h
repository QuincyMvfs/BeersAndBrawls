// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EDuelingStatus.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class UStatusEffectComponent;
class UAbilityInfo;
struct FCombatPatterns;
enum class ECombatKey : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatPatternReceived, FCombatPatterns, CombatPattern);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCombatPatternCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatPatternSegmentCompleted, int, SegmentNum);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectInputGiven, ECombatKey, InputKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFailInputGiven, ECombatKey, InputKey);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnElectrocuted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnElectrocuteEnded);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Events
	UPROPERTY(BlueprintAssignable)
	FOnCombatPatternReceived OnCombatPatternReceived;

	UPROPERTY(BlueprintAssignable)
	FOnCombatPatternCompleted OnCombatPatternCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FOnCombatPatternSegmentCompleted OnCombatPatternSegmentCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FOnCorrectInputGiven OnCorrectInputGiven;
	
	UPROPERTY(BlueprintAssignable)
	FOnFailInputGiven OnFailInputGiven;
	
	UPROPERTY(BlueprintAssignable)
	FOnElectrocuted OnElectrocutedEvent;
    	
	UPROPERTY(BlueprintAssignable)
	FOnElectrocuteEnded OnElectrocuteEndedEvent;
	//

	// Input Logic
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	bool M_CanReceiveInputs = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	EDuelingStatus M_DuelingStatus;
	
	UFUNCTION()
	void ReceiveInput(ECombatKey InputKey);

	UFUNCTION(BlueprintCallable)
	void StopInputs();
	//

	// Abilities
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(HideInDetailPanel))
	UAbilityInfo* SelectedAbility;
	//
	
	// Patterns
	UFUNCTION(BlueprintCallable)
	void GenerateRandomPatterns(UAbilityInfo* Ability, UCombatComponent* Victim);
	FCombatPatterns GenerateRandomCombatPattern(UAbilityInfo* Ability);
	FCombatPatterns GenerateRandomCounterPattern(UAbilityInfo* Ability, UCombatComponent* Victim);

	UFUNCTION(BlueprintCallable)
	void SetCombatPattern(FCombatPatterns NewCombatPattern);
	
	UFUNCTION(BlueprintCallable)
	void SetCanReceiveInputs(bool CanReceiveInputs);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	FCombatPatterns M_SelectedCombatPattern;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	FCombatPatterns M_SelectedCounterPattern;

	// Total Inputs
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	TArray<ECombatKey> M_RemainingInputs;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	int M_ActiveInputIndex;

	// Total Segments
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	TArray<FCombatPatterns> M_ActiveRemainingSegments;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	int M_ActiveSegmentIndex;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	int M_InputSegmentThreshold;
	
	int M_TotalPatterns = 0;
	
	//
	
	// ELECTROCUTION
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(HideInDetailPanel))
	bool M_IsElectrocuted = false;
	
	float M_InterruptionGap;
	float M_InterruptionDelay;
	int M_ElectrocutionTier;
	FTimerHandle M_ElectrocuteLoopTimer;
	FTimerHandle M_ElectrocuteTimer;
	
	void SetElectrocutionVariables(float InterruptionGap, float InterruptionTime, int EffectTier);
	void StartElectrocuting();
	void ElectrocutingLoop();
	void StopElectrocuting();
	//

	/// Status Effects
	// Dazed
	FCombatPatterns FactorInDazedModifier(FCombatPatterns Pattern, float Modifier);
	void AdjustDazedModifier(float Amount);
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(HideInDetailPanel))
	float M_Dazed_Modifier = 1.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(HideInDetailPanel))
	float M_Damage_Multiplier = 1.0f;
	
	void AdjustDamageModifier(float Amount);
	//
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(HideInDetailPanel))
	bool M_IsActiveUser = false;
};
