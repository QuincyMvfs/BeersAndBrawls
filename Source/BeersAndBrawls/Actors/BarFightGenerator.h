// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EAbilitySpeeds.h"
#include "GameFramework/Actor.h"
#include "BarFightGenerator.generated.h"

class ABeersAndBrawlsCharacter;
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats| Health")
	TArray<float> M_Health_Level_Multipliers = { 1, 1.2, 1.4, 2, 3, 4.5, 5};
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats| Health")
	int M_Health_Minimum = 80;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats| Health")
	int M_Health_Maximum = 150;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats| Speeds")
	TArray<float> M_Combat_Speeds = { 0.6, 0.45, 0.4, 0.35, 0.3, 0.25, 0.20, 0.15, 0.1 };

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stats| Speeds")
	TArray<float> M_Counter_Speeds = { 0.6, 0.45, 0.4, 0.35, 0.3, 0.25, 0.20, 0.15, 0.1 };
	// BASIC INFO END

	// REWARDS
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards")
	int M_Reward_MinimumCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards")
	int M_Reward_MaximumCurrency;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards")
	float M_Reward_MinimumExp;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Rewards")
	float M_Reward_MaximumExp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Bar Fight Generator")
	int M_FightsToGenerate = 4;

	// WEAPONS
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_Level_01_To_02_PossibleWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_Level_03_To_04_PossibleWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_Level_05_To_06_PossibleWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_Level_07_To_08_PossibleWeapons;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Instanced, Category = "Weapons")
	TArray<UWeapon*> M_Level_09_To_10_PossibleWeapons;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Enemy")
	UEnemyInfo* TemplateEnemy;

	ABeersAndBrawlsCharacter* PlayerRef;
	
public:
	FString GenerateRandomName();
	FString GenerateRandomDescription();
	UWeapon* GenerateRandomWeapon(int Level);
	int CalculateBeerBuxReward(int MaxHealth, int Level);
	int CalculateExpReward(int MaxHealth, int Level);
	EAbilitySpeeds GetSpeed(int Index);
	
	UFUNCTION(BlueprintCallable)
	FEnemyInfoStruct GenerateEnemyInfo(int Level);
};
