// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelingComponent.generated.h"


class UBeersAndBrawlsGameInstance;
class UAbilityInfo;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnLevelUp);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExperienceGained);

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
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	TArray<int> M_ExpRequiredPerLevel = {
		500, 1000, 1500, 2000, 2500, 3000, 4000, 5000, 7500, 10000, 999999999
	};

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_CurrentLevel = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_CurrentExp = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Levels")
	int M_SkillPoints = 0;

	UFUNCTION(BlueprintCallable)
	void AddExp(int AmountToAdd);
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> M_UnlockedAbilities;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetLevelInfo( UPARAM(DisplayName = "Current XP") int& OutCurrentXP,
		UPARAM(DisplayName = "XP Needed To Level Up") int& XPNeeded,
		UPARAM(DisplayName = "Current Level") int& OutCurrentLevel,
		UPARAM(DisplayName = "XP To Level Ratio") float& OutCurrentRatio
		);

	UBeersAndBrawlsGameInstance* GameInstanceRef;
};
