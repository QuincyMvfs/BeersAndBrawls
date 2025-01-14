// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "ActorComponents/CombatComponent.h"
#include "ActorComponents/HealthComponent.h"
#include "ActorComponents/InventoryComponent.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/DataAssets/AbilityPattern.h"
#include "BeersAndBrawls/Items/Weapon.h"

// Sets default values
AEnemy::AEnemy()
{
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("EnemyMesh"));
	EquippedStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshSlot"));
	EquippedStaticMeshComponent->SetupAttachment(SkeletalMesh, "WeaponSocket");
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemy::InitializeEnemy(FEnemyInfoStruct NewEnemyInfo)
{
	EnemyInfo = NewEnemyInfo;
	InventoryComponent->M_SelectedWeapon = EnemyInfo.EquippedWeapon;
	EquippedStaticMeshComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
}

void AEnemy::StartSendingCombatInputs(FCombatPatterns Pattern)
{
	AttackLoop.Invalidate();
	GetWorld()->GetTimerManager().ClearTimer(AttackLoop);
	CombatComponent->M_SelectedCombatPattern = Pattern;
	CombatComponent->SetCombatPattern(Pattern);
	
	GetWorld()->GetTimerManager().SetTimer(
		AttackLoop, this, &AEnemy::SendInput, 0.1f, true);
}

UAbilityInfo* AEnemy::GenerateRandomAbility()
{
	int RandInt = FMath::RandRange(0, InventoryComponent->M_SelectedWeapon->Abilities.Num());
	UAbilityInfo* SelectedAbility = InventoryComponent->M_SelectedWeapon->Abilities[RandInt];
	UE_LOG(LogTemp, Warning, TEXT("%s"), *SelectedAbility->M_AbilityName.ToString());
	return SelectedAbility;
}

void AEnemy::SendInput()
{
	ECombatKey Input = CombatComponent->M_SelectedCombatPattern.KeyInputs[InputIndex];
	CombatComponent->ReceiveInput(Input);
	InputIndex++;
}

