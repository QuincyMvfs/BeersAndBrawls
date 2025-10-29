// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizableCharacter.h"

#include "BeersAndBrawls/DataAssets/CosmeticInfo.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "BeersAndBrawls/Items/Weapon.h"

// Sets default values
ACustomizableCharacter::ACustomizableCharacter()
{
	SK_BaseMesh_Component = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SK_BaseMesh"));
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
	EquippedWeaponComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM_Weapon"));

	SK_Boots_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Gloves_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Head_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Teeth_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Beard_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Hair_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Eyes_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Eyebrows_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Shirt_Component->SetupAttachment(SK_BaseMesh_Component);
	SK_Pants_Component->SetupAttachment(SK_BaseMesh_Component);
	EquippedWeaponComponent->SetupAttachment(SK_BaseMesh_Component, "WeaponSocket");
}

// Called when the game starts or when spawned
void ACustomizableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	SK_Boots_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Beard_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Gloves_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Eyes_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Eyebrows_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Shirt_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Pants_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Head_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Teeth_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
	SK_Hair_Component->SetLeaderPoseComponent(SK_BaseMesh_Component);
}

void ACustomizableCharacter::SetupCosmetics(FEnemyInfoStruct NewEnemyInfo)
{
	EnemyInfo = NewEnemyInfo;
	
	UpdateCosmetics();

	if (EnemyInfo.EquippedWeapon)
	{
		if (EnemyInfo.EquippedWeapon->ItemMesh)
		{
			EquippedWeaponComponent->SetStaticMesh(EnemyInfo.EquippedWeapon->ItemMesh);
			
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("invalid mesh"))
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("invalid weapon"))
	}
}

void ACustomizableCharacter::UpdateCosmetics()
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

void ACustomizableCharacter::UpdateCosmeticColors(ECosmeticType CosmeticType)
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
			SkeletalMeshComponent2 = SK_BaseMesh_Component;
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
			SkeletalMeshComponent2 = SK_BaseMesh_Component;
			NewColor = EnemyInfo.Cosmetic_Colors[2];
			break;
	}
	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(CustomMaterial, this);
	SkeletalMeshComponent->SetMaterial(ElementIndex, DynamicMaterial);
	if (SkeletalMeshComponent2) { SkeletalMeshComponent2->SetMaterial(ElementIndex, DynamicMaterial); }
	
	DynamicMaterial->SetVectorParameterValue("Color", NewColor);
}

