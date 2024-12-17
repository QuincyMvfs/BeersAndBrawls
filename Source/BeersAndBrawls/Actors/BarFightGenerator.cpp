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

UEnemyInfo* ABarFightGenerator::GenerateEnemyInfo()
{
	if (TemplateEnemy)
	{
		TemplateEnemy->EnemyName = FText::FromString(GenerateRandomName());
		TemplateEnemy->EnemyDescription = FText::FromString(GenerateRandomDescription());
		TemplateEnemy->ExpReward = FMath::RoundToInt(FMath::RandRange(M_Reward_MinimumExp, M_Reward_MaximumExp));
		TemplateEnemy->BeerBuxReward = FMath::RandRange(M_Reward_MinimumCurrency, M_Reward_MaximumCurrency);
		TemplateEnemy->EquippedWeapon = GenerateRandomWeapon();
		TemplateEnemy->AttackSpeedMultiplier = FMath::TruncToFloat(FMath::RandRange(0.8, 1.2) * 100) / 100;
		TemplateEnemy->CounterSpeedMultiplier = FMath::TruncToFloat(FMath::RandRange(0.8, 1.2) * 100) / 100;
	}

	return TemplateEnemy;
}

