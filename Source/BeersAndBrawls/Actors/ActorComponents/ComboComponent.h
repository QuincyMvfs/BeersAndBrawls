// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "Components/ActorComponent.h"
#include "ComboComponent.generated.h"


class UAbilityInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnComboInitiated);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnComboUpdated, int, NewStreak, float, NewComboMultiplier);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UComboComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComboComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(BlueprintAssignable)
	FOnComboInitiated OnComboInitiatedEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnComboUpdated OnComboUpdatedEvent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	FCombatPatterns M_SelectedCombatPattern;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(HideInDetailPanel))
	UAbilityInfo* M_SelectedAbility;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_ComboStreak = 0;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float M_MinimumComboMultiplier = 0.5f;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float M_CurrentComboMultiplier;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float M_BaseMultiplier;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float M_ComboIncreaseInterval;
	
	
	UFUNCTION(BlueprintCallable)
	void InitiateCombo(UAbilityInfo* Ability, FCombatPatterns CombatPattern);
	
	UFUNCTION(BlueprintCallable)
	void UpdateCombo();
	
	UFUNCTION(BlueprintCallable)
	void ResetCombo();
};
