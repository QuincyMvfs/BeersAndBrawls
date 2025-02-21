// Fill out your copyright notice in the Description page of Project Settings.


#include "BarFightGenerator.h"

#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/DataAssets/EnemyInfo.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABarFightGenerator::ABarFightGenerator()
{

}

// Called when the game starts or when spawned
void ABarFightGenerator::BeginPlay()
{
	Super::BeginPlay();
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Name Generator
FString ABarFightGenerator::GenerateRandomName()
{
	if (M_RandomName_Titles.Num() <= 0 ||
		M_RandomName_FirstNames.Num() <= 0 ||
		M_RandomName_LastNames.Num() <= 0)
	{
		FString FakeName = "No Name";
		return FakeName;
	}
	
	int RandInt = FMath::RandRange(0, M_RandomName_Titles.Num() -1);
	const FString Title = M_RandomName_Titles[RandInt];
	RandInt = FMath::RandRange(0, M_RandomName_FirstNames.Num() -1);
	const FString FirstName = M_RandomName_FirstNames[RandInt];
	RandInt = FMath::RandRange(0, M_RandomName_LastNames.Num() -1);
	const FString LastName = M_RandomName_LastNames[RandInt];

	const FString FullName = Title + " " + FirstName + " " + LastName;
	return FullName;
}

// Description Generator
FString ABarFightGenerator::GenerateRandomDescription()
{
	if (M_RandomName_Descriptions.Num() <= 0)
	{
		const FString FakeDescription = "No Description";
		return FakeDescription;
	}

	const int RandInt = FMath::RandRange(0, M_RandomName_Descriptions.Num() -1);
	const FString ChosenDescription = M_RandomName_Descriptions[RandInt];

	return ChosenDescription;
}

// Weapon Generator
UWeapon* ABarFightGenerator::GenerateRandomWeapon()
{
	if (M_AllPossibleWeapons.Num() <= 0)
	{
		UWeapon* Weapon = nullptr;
		const FString FakeName = "NULL";
		Weapon->ItemName = FText::FromString(FakeName);
		return Weapon;
	}

	int RandInt = FMath::RandRange(0, M_AllPossibleWeapons.Num() -1);
	return M_AllPossibleWeapons[RandInt];
}

int ABarFightGenerator::CalculateBeerBuxReward(float CombatSpeed, float CounterSpeed, int MaxHealth)
{
	int TotalReward = FMath::RandRange(M_Reward_MinimumCurrency, M_Reward_MaximumCurrency);
	const int AttackSpeedReward = TotalReward * (M_AttackSpeed_Maximum / CombatSpeed);
	const int CounterSpeedReward = TotalReward * (M_CounterSpeed_Maximum / CounterSpeed);
	const int HealthReward = TotalReward * (MaxHealth / (M_Health_Maximum / 5));
	TotalReward = (TotalReward + (AttackSpeedReward + CounterSpeedReward + HealthReward)) / 50;
	
	return TotalReward;
}

int ABarFightGenerator::CalculateExpReward(float CombatSpeed, float CounterSpeed, int MaxHealth)
{
	int TotalReward = FMath::RoundToInt(FMath::RandRange(M_Reward_MinimumExp, M_Reward_MaximumExp));
	const int AttackSpeedReward = TotalReward * (M_AttackSpeed_Maximum / CombatSpeed);
	const int CounterSpeedReward = TotalReward * (M_CounterSpeed_Maximum / CounterSpeed);
	const int HealthReward = TotalReward * (MaxHealth / (M_Health_Maximum / 5));
	TotalReward = (TotalReward + (AttackSpeedReward + CounterSpeedReward + HealthReward)) / 50;
	
	return TotalReward;
}

FEnemyInfoStruct ABarFightGenerator::GenerateEnemyInfo()
{
	FEnemyInfoStruct NewEnemy;
	NewEnemy.EnemyName = FText::FromString(GenerateRandomName());
	NewEnemy.EnemyDescription = FText::FromString(GenerateRandomDescription());
	NewEnemy.EquippedWeapon = GenerateRandomWeapon();
	
	float AttackSpeedMultiplier = FMath::TruncToFloat(FMath::RandRange(M_AttackSpeed_Minimum, M_AttackSpeed_Maximum) * 100) / 100;
	AttackSpeedMultiplier *= PlayerRef->M_CombatSpeedMultiplier;
	NewEnemy.AttackSpeedMultiplier = AttackSpeedMultiplier;
	
	float CounterSpeedMultiplier = FMath::TruncToFloat(FMath::RandRange(M_CounterSpeed_Minimum, M_CounterSpeed_Maximum) * 100) / 100;
	CounterSpeedMultiplier *= PlayerRef->M_CounterSpeedMultiplier;
	NewEnemy.CounterSpeedMultiplier = CounterSpeedMultiplier;
	
	const int MaxHealth = FMath::RandRange(M_Health_Minimum, M_Health_Maximum);
	NewEnemy.MaxHealth = MaxHealth;

	NewEnemy.BeerBuxReward = CalculateBeerBuxReward(AttackSpeedMultiplier, CounterSpeedMultiplier, MaxHealth);
	NewEnemy.ExpReward = CalculateExpReward(AttackSpeedMultiplier, CounterSpeedMultiplier, MaxHealth);
	
	return NewEnemy;
}

