// Fill out your copyright notice in the Description page of Project Settings.


#include "BarFightGenerator.h"

#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/BeersAndBrawlsGameInstance.h"
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
	DefaultGameInstanceRef = Cast<UBeersAndBrawlsGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
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
UWeapon* ABarFightGenerator::GenerateRandomWeapon(int Level = 1)
{
	TArray<UWeapon*> WeaponArray;
	
	switch (Level)
	{
		case 1:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 2:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 3:
			WeaponArray = M_Level_01_To_02_PossibleWeapons;
			break;
		case 4:
			WeaponArray = M_Level_03_To_04_PossibleWeapons;
			break;
		case 5:
			WeaponArray = M_Level_03_To_04_PossibleWeapons;
			break;
		case 6:
			WeaponArray = M_Level_05_To_06_PossibleWeapons;
			break;
		case 7:
			WeaponArray = M_Level_05_To_06_PossibleWeapons;
			break;
		case 8:
			WeaponArray = M_Level_07_To_08_PossibleWeapons;
			break;
		case 9:
			WeaponArray = M_Level_07_To_08_PossibleWeapons;
			break;
		case 10:
			WeaponArray = M_Level_09_To_10_PossibleWeapons;
			break;
		default:
			WeaponArray = M_Level_09_To_10_PossibleWeapons;
			break;
	}
	
	int RandInt = FMath::RandRange(0, WeaponArray.Num() -1);
	//UE_LOG(LogTemp, Warning, TEXT("rand %i | max %i"), RandInt, WeaponArray.Num() - 1);
	//UE_LOG(LogTemp, Warning, TEXT("Player Level %i"), Level);
	return WeaponArray[RandInt];
}

int ABarFightGenerator::CalculateBeerBuxReward(int MaxHealth, int Level)
{
	int TotalReward = FMath::RandRange(M_Reward_MinimumCurrency, M_Reward_MaximumCurrency);
	
	const int HealthReward = TotalReward * (MaxHealth / M_Health_Maximum);
	TotalReward = TotalReward + HealthReward;
	TotalReward *= Level;
	
	return TotalReward;
}

int ABarFightGenerator::CalculateExpReward(int MaxHealth, int Level)
{
	int TotalReward = FMath::RandRange(M_Reward_MinimumExp, M_Reward_MaximumExp);
	
	const int HealthReward = TotalReward * (MaxHealth / M_Health_Maximum);
	TotalReward = TotalReward + HealthReward;
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
			SelectedSpeed = EAbilitySpeeds::Very_Quick;
			break;
	}

	return SelectedSpeed;
}

TArray<UCosmeticInfo*> ABarFightGenerator::GenerateRandomCosmeticInfo()
{
	if (!DefaultGameInstanceRef) return TArray<UCosmeticInfo*>();

	TArray<UCosmeticInfo*> CosmeticInfos;
	CosmeticInfos.Add(DefaultGameInstanceRef->Boots[FMath::RandRange(0, DefaultGameInstanceRef->Boots.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Gloves[FMath::RandRange(0, DefaultGameInstanceRef->Gloves.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Heads[FMath::RandRange(0, DefaultGameInstanceRef->Heads.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Teeth[FMath::RandRange(0, DefaultGameInstanceRef->Teeth.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Beards[FMath::RandRange(0, DefaultGameInstanceRef->Beards.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Hair[FMath::RandRange(0, DefaultGameInstanceRef->Hair.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Eyes[FMath::RandRange(0, DefaultGameInstanceRef->Eyes.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Eyebrows[FMath::RandRange(0, DefaultGameInstanceRef->Eyebrows.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Shirts[FMath::RandRange(0, DefaultGameInstanceRef->Shirts.Num() - 1)]);
	CosmeticInfos.Add(DefaultGameInstanceRef->Pants[FMath::RandRange(0, DefaultGameInstanceRef->Pants.Num() - 1)]);

	return CosmeticInfos;
	
}

TArray<FLinearColor> ABarFightGenerator::GenerateRandomColors()
{
	if (!DefaultGameInstanceRef) return TArray<FLinearColor>();

	TArray<FLinearColor> Colors;
	Colors.Add(DefaultGameInstanceRef->Boot_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Boot_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Gloves_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Gloves_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Skin_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Skin_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Teeth_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Teeth_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Hair_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Hair_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Hair_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Hair_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Eye_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Eye_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Hair_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Hair_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Shirt_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Shirt_ColorPalette.Num() - 1)]);
	Colors.Add(DefaultGameInstanceRef->Pants_ColorPalette[FMath::RandRange(0, DefaultGameInstanceRef->Pants_ColorPalette.Num() - 1)]);

	return Colors;

}

FEnemyInfoStruct ABarFightGenerator::GenerateEnemyInfo(int Level)
{
	FEnemyInfoStruct NewEnemy;

	// Text Info
	NewEnemy.EnemyName = FText::FromString(GenerateRandomName());
	NewEnemy.EnemyDescription = FText::FromString(GenerateRandomDescription());
	
	// Combat Speed
	int RandomAttackSpeedIndex = FMath::RandRange(0, Level);
	RandomAttackSpeedIndex = FMath::Clamp(RandomAttackSpeedIndex, 0, M_Combat_Speeds.Num() - 1);
	float AttackSpeedMultiplier = M_Combat_Speeds[RandomAttackSpeedIndex];
	AttackSpeedMultiplier *= PlayerRef->M_CombatSpeedMultiplier;
	NewEnemy.AttackSpeedMultiplier = AttackSpeedMultiplier;
	RandomAttackSpeedIndex = FMath::RandRange(0, Level + 3);
	NewEnemy.AttackSpeed = GetSpeed(RandomAttackSpeedIndex);

	// Counter Speed
	int RandomCounterSpeedIndex = FMath::RandRange(0, Level);
	RandomCounterSpeedIndex = FMath::Clamp(RandomCounterSpeedIndex, 0, M_Counter_Speeds.Num() - 1);
	float CounterSpeedMultiplier = M_Counter_Speeds[RandomCounterSpeedIndex];
	CounterSpeedMultiplier *= PlayerRef->M_CounterSpeedMultiplier;
	NewEnemy.CounterSpeedMultiplier = CounterSpeedMultiplier;
	RandomCounterSpeedIndex = FMath::RandRange(0, Level + 3);
	NewEnemy.CounterSpeed = GetSpeed(RandomCounterSpeedIndex);

	// Max Health
	int HealthMultiplierIndex = Level;
	HealthMultiplierIndex = FMath::Clamp(HealthMultiplierIndex, 0, M_Health_Level_Multipliers.Num() - 1);
	const int MaxHealth = FMath::RandRange(M_Health_Minimum, M_Health_Maximum) * M_Health_Level_Multipliers[HealthMultiplierIndex];
	NewEnemy.MaxHealth = MaxHealth;

	// Rewards
	NewEnemy.BeerBuxReward = CalculateBeerBuxReward(MaxHealth, Level);
	NewEnemy.ExpReward = CalculateExpReward(MaxHealth, Level);

	//UE_LOG(LogTemp, Warning, TEXT("%i"), Level);
	NewEnemy.EquippedWeapon = GenerateRandomWeapon(Level);
	if (!NewEnemy.EquippedWeapon)
	{
		NewEnemy.EquippedWeapon = GenerateRandomWeapon(Level + 1);
	}
	
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *NewEnemy.EquippedWeapon->ItemName.ToString());

	NewEnemy.EnemyLevel = Level;

	// Cosmetics
	NewEnemy.Cosmetics = GenerateRandomCosmeticInfo();
	NewEnemy.Cosmetic_Colors = GenerateRandomColors();
	
	return NewEnemy;
}

FEnemyInfoStruct ABarFightGenerator::GetBossEnemy(int Level)
{
	FEnemyInfoStruct Boss;
	
	switch (Level)
	{
		case 1:
			Boss = M_Boss_Level_01->EnemyInfoStruct;
			break;
		case 2:
			Boss = M_Boss_Level_02->EnemyInfoStruct;
			break;
		case 3:
			Boss = M_Boss_Level_03->EnemyInfoStruct;
			break;
		case 4:
			Boss = M_Boss_Level_04->EnemyInfoStruct;
			break;
		case 5:
			Boss = M_Boss_Level_05->EnemyInfoStruct;
			break;
		default:
			Boss = M_Boss_Level_01->EnemyInfoStruct;
			break;
	}

	return Boss;
}

