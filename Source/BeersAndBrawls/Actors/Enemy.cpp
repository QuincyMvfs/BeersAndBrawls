// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

#include "ActorComponents/CombatComponent.h"
#include "ActorComponents/HealthComponent.h"
#include "ActorComponents/InventoryComponent.h"
#include "ActorComponents/StatusEffectComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/DataAssets/AbilityInfo.h"
#include "BeersAndBrawls/DataAssets/AbilityPattern.h"
#include "BeersAndBrawls/DataAssets/CosmeticInfo.h"
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

	SetupCustomizationMeshs();
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();

	SK_Boots_Component->SetLeaderPoseComponent(GetMesh());
	SK_Beard_Component->SetLeaderPoseComponent(GetMesh());
	SK_Gloves_Component->SetLeaderPoseComponent(GetMesh());
	SK_Eyes_Component->SetLeaderPoseComponent(GetMesh());
	SK_Eyebrows_Component->SetLeaderPoseComponent(GetMesh());
	SK_Shirt_Component->SetLeaderPoseComponent(GetMesh());
	SK_Pants_Component->SetLeaderPoseComponent(GetMesh());
	SK_Head_Component->SetLeaderPoseComponent(GetMesh());
	SK_Teeth_Component->SetLeaderPoseComponent(GetMesh());
	SK_Hair_Component->SetLeaderPoseComponent(GetMesh());
}

void AEnemy::InitializeEnemy(FEnemyInfoStruct NewEnemyInfo)
{
	EnemyInfo = NewEnemyInfo;
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
	InventoryComponent->M_SelectedWeapon = EnemyInfo.EquippedWeapon;
	HealthComponent->SetMaxHealth(EnemyInfo.MaxHealth);
	EquippedWeaponComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
	UpdateCosmetics();
	
}

void AEnemy::SetupCustomizationMeshs()
{
	SK_Boots_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Boots"));
	SK_Gloves_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Gloves"));
	SK_Head_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Head"));
	SK_Teeth_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Teeth"));
	SK_Beard_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Beard"));
	SK_Hair_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Hair"));
	SK_Eyes_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Eyes"));
	SK_Eyebrows_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Eyebrows"));
	SK_Shirt_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Shirts"));
	SK_Pants_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_Pants"));

	SK_Boots_Component->SetupAttachment(GetMesh());
	SK_Gloves_Component->SetupAttachment(GetMesh());
	SK_Head_Component->SetupAttachment(GetMesh());
	SK_Teeth_Component->SetupAttachment(GetMesh());
	SK_Beard_Component->SetupAttachment(GetMesh());
	SK_Hair_Component->SetupAttachment(GetMesh());
	SK_Eyes_Component->SetupAttachment(GetMesh());
	SK_Eyebrows_Component->SetupAttachment(GetMesh());
	SK_Shirt_Component->SetupAttachment(GetMesh());
	SK_Pants_Component->SetupAttachment(GetMesh());
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
	
	float AttackSpeed;
	if (IsDefending)
	{
		AttackSpeed = EnemyInfo.CounterSpeedMultiplier;
		GetWorld()->GetTimerManager().SetTimer(
			AttackLoop, this, &AEnemy::SendInput, AttackSpeed, true);
	}
	else
	{
		AttackSpeed = EnemyInfo.AttackSpeedMultiplier;
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

void AEnemy::UpdateCosmetics()
{
	SK_Boots_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[0]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Boots);
	SK_Gloves_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[1]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Gloves);
	SK_Head_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[2]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Head);
	SK_Teeth_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[3]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Teeth);
	SK_Beard_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[4]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Beard);
	SK_Hair_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[5]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Hair);
	SK_Eyes_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[6]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Eyes);
	SK_Eyebrows_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[7]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Eyebrows);
	SK_Shirt_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[8]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Shirt);
	SK_Pants_Component->SetSkeletalMesh(EnemyInfo.Cosmetics[9]->SkeletalMesh);
	UpdateCosmeticColors(ECosmeticType::Pants);
}

void AEnemy::UpdateCosmeticColors(ECosmeticType CosmeticType)
{
	FLinearColor NewColor;
	USkeletalMeshComponent* SkeletalMeshComponent;
	USkeletalMeshComponent* SkeletalMeshComponent2 = nullptr;
	int ElementIndex = 0;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			SkeletalMeshComponent = SK_Boots_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[0];
			break;
		case ECosmeticType::Gloves:
			SkeletalMeshComponent = SK_Gloves_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[1];
			break;
		case ECosmeticType::Head:
			SkeletalMeshComponent = SK_Head_Component;
			SkeletalMeshComponent2 = GetMesh();
			NewColor = EnemyInfo.Cosmetic_Colors[2];
			break;
		case ECosmeticType::Teeth:
			SkeletalMeshComponent = SK_Teeth_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[3];
			break;
		case ECosmeticType::Beard:
			SkeletalMeshComponent = SK_Beard_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[4];
			break;
		case ECosmeticType::Hair:
			SkeletalMeshComponent = SK_Hair_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[4];
			break;
		case ECosmeticType::Eyebrows:
			SkeletalMeshComponent = SK_Eyebrows_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[4];
			break;
		case ECosmeticType::Eyes:
			SkeletalMeshComponent = SK_Eyes_Component;
			ElementIndex = 2;
			NewColor = EnemyInfo.Cosmetic_Colors[5];
			break;
		case ECosmeticType::Shirt:
			SkeletalMeshComponent = SK_Shirt_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[6];
			break;
		case ECosmeticType::Pants:
			SkeletalMeshComponent = SK_Pants_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[7];
			break;
		default:
			SkeletalMeshComponent = SK_Head_Component;
			SkeletalMeshComponent2 = GetMesh();
			NewColor = EnemyInfo.Cosmetic_Colors[2];
			break;
	}
	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(CustomMaterial, PlayerRef);
	SkeletalMeshComponent->SetMaterial(ElementIndex, DynamicMaterial);
	if (SkeletalMeshComponent2) { SkeletalMeshComponent2->SetMaterial(ElementIndex, DynamicMaterial); }
	
	DynamicMaterial->SetVectorParameterValue("Color", NewColor);
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

