// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilityShop.generated.h"

class UAbilityInfo;

UCLASS()
class BEERSANDBRAWLS_API AAbilityShop : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAbilityShop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Weapon Abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_BluntAbilitiesToBuy;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_BluntAbilitiesIndex = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_ChopAbilitiesToBuy;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_ChopAbilitiesIndex = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_SlashAbilitiesToBuy;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_SlashAbilitiesIndex = 0;
	
	// Generic Abilities
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<float> M_HealthUpgradesToBuy{ 1.1, 1.2, 1.3, 1.4, 1.5 };
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_HealthUpgradeIndex = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<float> M_DamageUpgradesToBuy{ 1.1, 1.2, 1.3, 1.4, 1.5 };
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_DamageUpgradeIndex = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<float> M_CombatUpgradesToBuy{ 0.9, 0.8, 0.7, 0.6, 0.5 };
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_CombatUpgradeIndex = 0;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<float> M_CounterUpgradesToBuy{ 0.9, 0.8, 0.7, 0.6, 0.5 };
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_CounterUpgradeIndex = 0;
	
};
