// Fill out your copyright notice in the Description page of Project Settings.


#include "BarFightGenerator.h"

#include "BeersAndBrawls/DataAssets/EnemyInfo.h"
#include "BeersAndBrawls/Items/Weapon.h"

// Sets default values
ABarFightGenerator::ABarFightGenerator()
{

}

// Called when the game starts or when spawned
void ABarFightGenerator::BeginPlay()
{
	Super::BeginPlay();
	
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
	
	int RandInt = FMath::RandRange(0, M_RandomName_Titles.Num());
	const FString Title = M_RandomName_Titles[RandInt];
	RandInt = FMath::RandRange(0, M_RandomName_FirstNames.Num());
	const FString FirstName = M_RandomName_FirstNames[RandInt];
	RandInt = FMath::RandRange(0, M_RandomName_LastNames.Num());
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

	const int RandInt = FMath::RandRange(0, M_RandomName_Descriptions.Num());
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

	const int RandInt = FMath::RandRange(0, M_AllPossibleWeapons.Num());
	return M_AllPossibleWeapons[RandInt];
}

UEnemyInfo* ABarFightGenerator::GenerateEnemyInfo()
{
	UWorld* World = GEngine->GetWorldFromContextObjectChecked(this);
	UEnemyInfo* NewEnemy = NewObject<UEnemyInfo>(World);

	if (NewEnemy)
	{
		NewEnemy->EnemyName = FText::FromString(GenerateRandomName());
		NewEnemy->EnemyDescription = FText::FromString(GenerateRandomDescription());
		NewEnemy->ExpReward = FMath::RandRange(M_Reward_MinimumExp, M_Reward_MaximumExp);
		NewEnemy->BeerBuxReward = FMath::RandRange(M_Reward_MinimumCurrency, M_Reward_MaximumCurrency);
		NewEnemy->AttackSpeedMultiplier = FMath::RandRange(0.8, 1.2);
		NewEnemy->CounterSpeedMultiplier = FMath::RandRange(0.8, 1.2);
		NewEnemy->EquippedWeapon = GenerateRandomWeapon();
	}

	return NewEnemy;
}

