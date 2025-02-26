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
UWeapon* ABarFightGenerator::GenerateRandomWeapon(int Level)
{
	TArray<UWeapon*> WeaponArray;
	
	switch (Level)
	{
		case 0:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 1:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 2:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 3:
			WeaponArray = M_Level_03_To_04_PossibleWeapons;
			break;
		case 4:
			WeaponArray = M_Level_03_To_04_PossibleWeapons;
			break;
		case 5:
			WeaponArray = M_Level_05_To_06_PossibleWeapons;
			break;
		case 6:
			WeaponArray = M_Level_05_To_06_PossibleWeapons;
			break;
		case 7:
			WeaponArray = M_Level_07_To_08_PossibleWeapons;
			break;
		case 8:
			WeaponArray = M_Level_07_To_08_PossibleWeapons;
			break;
		case 9:
			WeaponArray = M_Level_09_To_10_PossibleWeapons;
			break;
	}
	
	int RandInt = FMath::RandRange(0, WeaponArray.Num() -1);
	return WeaponArray[RandInt];
}

int ABarFightGenerator::CalculateBeerBuxReward(int MaxHealth, int Level)
{
	int TotalReward = FMath::RandRange(M_Reward_MinimumCurrency, M_Reward_MaximumCurrency);
	const int AttackSpeedReward = TotalReward * (M_Combat_Speeds.Last() / M_Combat_Speeds[Level]);     
	const int CounterSpeedReward = TotalReward * (M_Counter_Speeds.Last() / M_Counter_Speeds[Level]);   
	const int HealthReward = TotalReward * (MaxHealth / (M_Health_Maximum / 5));
	TotalReward = (TotalReward + (AttackSpeedReward + CounterSpeedReward + HealthReward)) / 50;
	TotalReward *= Level;
	
	return TotalReward;
}

int ABarFightGenerator::CalculateExpReward(int MaxHealth, int Level)
{
	int TotalReward = FMath::RoundToInt(FMath::RandRange(M_Reward_MinimumExp, M_Reward_MaximumExp));
	const int AttackSpeedReward = TotalReward * (M_Combat_Speeds.Last() / M_Combat_Speeds[Level]);
	const int CounterSpeedReward = TotalReward * (M_Counter_Speeds.Last() / M_Counter_Speeds[Level]);
	const int HealthReward = TotalReward * (MaxHealth / (M_Health_Maximum / 5));
	TotalReward = (TotalReward + (AttackSpeedReward + CounterSpeedReward + HealthReward)) / 50;
	TotalReward *= Level;
	
	return TotalReward;
}

EAbilitySpeeds ABarFightGenerator::GetSpeed(int Index)
{
	if (Index > M_Combat_Speeds.Num()) Index = M_Combat_Speeds.Num() - 1;
	
	EAbilitySpeeds SelectedSpeed = EAbilitySpeeds::Average;
	
	switch (Index)
	{
		case 0:
			SelectedSpeed = EAbilitySpeeds::Impossibly_Slow;
			break;
		case 1:
			SelectedSpeed = EAbilitySpeeds::Comically_Slow;
			break;
		case 2:
			SelectedSpeed = EAbilitySpeeds::Very_Slow;
			break;
		case 3:
			SelectedSpeed = EAbilitySpeeds::Sluggish;
			break;
		case 4:
			SelectedSpeed = EAbilitySpeeds::Average;
			break;
		case 5:
			SelectedSpeed = EAbilitySpeeds::Quick;
			break;
		case 6:
			SelectedSpeed = EAbilitySpeeds::Very_Quick;
			break;
		case 7:
			SelectedSpeed = EAbilitySpeeds::Insanely_Fast;
			break;
		case 8:
			SelectedSpeed = EAbilitySpeeds::Unfathomably_Fast;
			break;
		default:
			SelectedSpeed = EAbilitySpeeds::Average;
			break;
	}

	return SelectedSpeed;
}

FEnemyInfoStruct ABarFightGenerator::GenerateEnemyInfo(int Level)
{
	FEnemyInfoStruct NewEnemy;

	// Text Info
	NewEnemy.EnemyName = FText::FromString(GenerateRandomName());
	NewEnemy.EnemyDescription = FText::FromString(GenerateRandomDescription());
	
	// Combat Speed
	int RandomAttackSpeedIndex = FMath::RandRange(0, Level);
	float AttackSpeedMultiplier = M_Combat_Speeds[RandomAttackSpeedIndex];
	AttackSpeedMultiplier *= PlayerRef->M_CombatSpeedMultiplier;
	NewEnemy.AttackSpeedMultiplier = AttackSpeedMultiplier;
	RandomAttackSpeedIndex = FMath::RandRange(0, Level + 3);
	NewEnemy.AttackSpeed = GetSpeed(RandomAttackSpeedIndex);

	// Counter Speed
	int RandomCounterSpeedIndex = FMath::RandRange(0, Level);
	float CounterSpeedMultiplier = M_Counter_Speeds[RandomCounterSpeedIndex];
	CounterSpeedMultiplier *= PlayerRef->M_CounterSpeedMultiplier;
	NewEnemy.CounterSpeedMultiplier = CounterSpeedMultiplier;
	RandomCounterSpeedIndex = FMath::RandRange(0, Level + 3);
	NewEnemy.CounterSpeed = GetSpeed(RandomCounterSpeedIndex);

	// Max Health
	const int MaxHealth = FMath::RandRange(M_Health_Minimum, M_Health_Maximum);
	NewEnemy.MaxHealth = MaxHealth;

	// Rewards
	NewEnemy.BeerBuxReward = CalculateBeerBuxReward(MaxHealth, Level);
	NewEnemy.ExpReward = CalculateExpReward(MaxHealth, Level);
	
	NewEnemy.EquippedWeapon = GenerateRandomWeapon(Level);

	NewEnemy.EnemyLevel = Level;
	
	return NewEnemy;
}

