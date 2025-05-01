// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "ActorComponents/CombatComponent.h"
#include "ActorComponents/HealthComponent.h"
#include "ActorComponents/InventoryComponent.h"
#include "ActorComponents/StatusEffectComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/DataAssets/AbilityPattern.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemy::AEnemy()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	StatusEffectComponent = CreateDefaultSubobject<UStatusEffectComponent>(TEXT("StatusEffectComponent"));
	EquippedWeaponComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TheWeaponSocket"));
	EquippedWeaponComponent->SetupAttachment(GetMesh(), "WeaponSocket");
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::InitializeEnemy(FEnemyInfoStruct NewEnemyInfo)
{
	EnemyInfo = NewEnemyInfo;
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	InventoryComponent->M_SelectedWeapon = EnemyInfo.EquippedWeapon;
	HealthComponent->SetMaxHealth(EnemyInfo.MaxHealth);
	EquippedWeaponComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
	
}

void AEnemy::StartSendingCombatInputs(FCombatPatterns Pattern, bool IsDefending)
{
	if (GetWorld()->GetTimerManager().IsTimerActive(AttackLoop))
	{
		StopSendingInputs();
	}
	
	CombatComponent->M_SelectedCombatPattern = Pattern;
	CombatComponent->SetCombatPattern(Pattern);
	InputIndex = 0;
	
	if (IsDefending)
	{
		float AttackSpeed = EnemyInfo.CounterSpeedMultiplier;
		GetWorld()->GetTimerManager().SetTimer(
			AttackLoop, this, &AEnemy::SendInput, AttackSpeed, true);
	}
	else
	{
		float AttackSpeed = EnemyInfo.AttackSpeedMultiplier;
		GetWorld()->GetTimerManager().SetTimer(
			AttackLoop, this, &AEnemy::SendInput, AttackSpeed, true);
	}
}

void AEnemy::StopSendingInputs()
{
	GetWorld()->GetTimerManager().ClearTimer(AttackLoop);
	AttackLoop.Invalidate();

	InputIndex = 0;
}

UAbilityInfo* AEnemy::GenerateRandomAbility()
{
	int RandInt = FMath::RandRange(0, InventoryComponent->M_SelectedWeapon->Abilities.Num() - 1);
	UAbilityInfo* SelectedAbility = InventoryComponent->M_SelectedWeapon->Abilities[RandInt];
	return SelectedAbility;
}

void AEnemy::SendInput()
{
	if (InputIndex > CombatComponent->M_SelectedCombatPattern.KeyInputs.Num() -1)
	{
		StopSendingInputs();
		return;
	}
	
	ECombatKey Input = CombatComponent->M_SelectedCombatPattern.KeyInputs[InputIndex];
	
	if (CombatComponent->M_CanReceiveInputs)
	{
		CombatComponent->ReceiveInput(Input);
		InputIndex++;
	}
}

