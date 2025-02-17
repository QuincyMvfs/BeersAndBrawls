// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarFightGenerator.generated.h"

struct FEnemyInfoStruct;
class UEnemyInfo;
class UWeapon;

UCLASS()
class BEERSANDBRAWLS_API ABarFightGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarFightGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// BASIC NAME INFO
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Name Info")
	TArray<FString> M_RandomName_Titles {
		"Mr", "Mrs", "Sir", "Boss", "Chief", "King", "Queen", "Prince", "Princess", "Unc" 
	};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Name Info")
	TArray<FString> M_RandomName_FirstNames {
		"Keef", "Liam", "Nathaniel", "Bobby", "Idaho", "Shidney", "Fartrinse", "Guacafuck", "Skbiidi" 
	};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Name Info")
	TArray<FString> M_RandomName_LastNames {
		"the Second", "Michelangelo", "McChugger", "Beeranium", "Boozer", "Drunkard", "Drinkster", "Brewer", "Bally-T-Fricer" 
	};

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Name Info")
	TArray<FString> M_RandomName_Descriptions {
		"Now this guy is fucking retarded", "A true ball tugger", "Millions will drink when this fella walks in the room",
		"Brews and Beers and Booze and Drinks yeah im on meth", "I have a gun, and i want to shoot you!",
		"The Shittiest Pisser in the room", "I will suck you off buddy", "Blah blah blah suck my cock pal", "kill yourself, NOW!" 
	};

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "50", ClampMax = "200", UIMin = "50", UIMax = "200"))
	int M_Health_Minimum = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "201", ClampMax = "50000", UIMin = "201", UIMax = "5000"))
	int M_Health_Maximum = 500;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "0.03", ClampMax = "0.4", UIMin = "0.1", UIMax = "0.4"))
	float M_AttackSpeed_Minimum = 0.03;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "0.5", ClampMax = "1.1", UIMin = "0.5", UIMax = "1.1"))
	float M_AttackSpeed_Maximum = 1.1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "0.03", ClampMax = "0.4", UIMin = "0.1", UIMax = "0.4"))
	float M_CounterSpeed_Minimum = 0.03;                                                                   
                                                                   
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats", meta = (ClampMin = "0.5", ClampMax = "1.1", UIMin = "0.5", UIMax = "1.1"))
	float M_CounterSpeed_Maximum = 1.1;

	// BASIC INFO END

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bar Fight Generator")
	int M_FightsToGenerate = 4;

	// WEAPONS
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_AllPossibleWeapons;

	// REWARDS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards", meta = (ClampMin = "10", ClampMax = "500", UIMin = "10", UIMax = "500"))
	int M_Reward_MinimumCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards", meta = (ClampMin = "501", ClampMax = "2000", UIMin = "501", UIMax = "2000"))
	int M_Reward_MaximumCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards", meta = (ClampMin = "10.0", ClampMax = "500.0", UIMin = "10.0", UIMax = "500.0"))
	float M_Reward_MinimumExp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards", meta = (ClampMin = "501.0", ClampMax = "2000.0", UIMin = "501.0", UIMax = "2000.0"))
	float M_Reward_MaximumExp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	UEnemyInfo* TemplateEnemy;

public:
	FString GenerateRandomName();
	FString GenerateRandomDescription();
	UWeapon* GenerateRandomWeapon();
	int CalculateBeerBuxReward(float CombatSpeed, float CounterSpeed, int MaxHealth);
	int CalculateExpReward(float CombatSpeed, float CounterSpeed, int MaxHealth);
	
	UFUNCTION(BlueprintCallable)
	FEnemyInfoStruct GenerateEnemyInfo();
};
