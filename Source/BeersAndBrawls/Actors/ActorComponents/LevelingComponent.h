// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelingComponent.generated.h"


class ABeersAndBrawlsCharacter;
class UBeersAndBrawlsGameInstance;
class UAbilityInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExperienceGained);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSkillPointSpent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAbilitiesUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API ULevelingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULevelingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnLevelUp OnLevelUpEvent;

	UPROPERTY(BlueprintAssignable)
	FOnExperienceGained OnExperienceGainedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnSkillPointSpent OnSkillPointSpentEvent;
	
	UPROPERTY(BlueprintAssignable)
	FOnAbilitiesUpdated OnAbilitiesUpdatedEvent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	TArray<int> M_ExpRequiredPerLevel = {
		500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000, 999999999
	};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_CurrentLevel = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_CurrentExp = 501;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_SkillPoints = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_AllAbilities;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_UnlockedAbilities;
	
	UFUNCTION(BlueprintCallable)
	void AddExp(int AmountToAdd);

	void SpendSkillPoints(int Amount);

	void UpdateAllAbilities();
	
	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetLevelInfo( UPARAM(DisplayName = "Current XP") int& OutCurrentXP,
		UPARAM(DisplayName = "XP Needed To Level Up") int& XPNeeded,
		UPARAM(DisplayName = "Current Level") int& OutCurrentLevel,
		UPARAM(DisplayName = "XP To Level Ratio") float& OutCurrentRatio
		);

	UBeersAndBrawlsGameInstance* GameInstanceRef;

	ABeersAndBrawlsCharacter* PlayerRef;
};
