// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


class UAbilityInfo;
struct FCombatPatterns;
enum class ECombatKey : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatPatternReceived, FCombatPatterns, CombatPattern);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCombatPatternCompleted);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCorrectInputGiven, ECombatKey, InputKey);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFailInputGiven, ECombatKey, InputKey);
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
	UFUNCTION(BlueprintCallable)
	void GenerateRandomPatterns(UAbilityInfo* Ability);
	FCombatPatterns GenerateRandomCombatPattern(UAbilityInfo* Ability);
	FCombatPatterns GenerateRandomCounterPattern(UAbilityInfo* Ability);
	
	UFUNCTION(BlueprintCallable)
	void SetCombatPattern(FCombatPatterns NewCombatPattern);

	UFUNCTION()
	void ReceiveInput(ECombatKey InputKey);

	UFUNCTION(BlueprintCallable)
	void StopInputs();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FCombatPatterns M_SelectedCombatPattern;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FCombatPatterns M_SelectedCounterPattern;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UAbilityInfo* SelectedAbility;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool M_CanReceiveInputs = false;

	TArray<ECombatKey> M_RemainingInputs;
	
	UPROPERTY(BlueprintAssignable)
	FOnCombatPatternReceived OnCombatPatternReceived;

	UPROPERTY(BlueprintAssignable)
	FOnCombatPatternCompleted OnCombatPatternCompleted;
	
	UPROPERTY(BlueprintAssignable)
	FOnCorrectInputGiven OnCorrectInputGiven;
	
	UPROPERTY(BlueprintAssignable)
	FOnFailInputGiven OnFailInputGiven;

};
