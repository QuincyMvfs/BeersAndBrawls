// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"

#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(GetOwner());
}

// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();

	UpdateAllCosmetics();
}

// Updates all cosmetics to their currently selected cosmetics
void UCustomizationComponent::UpdateAllCosmetics()
{
	SwapCosmetic(C_Selected_Beard);
	SwapCosmetic(C_Selected_Boots);
	SwapCosmetic(C_Selected_Eyebrows);
	SwapCosmetic(C_Selected_Eyes);
	SwapCosmetic(C_Selected_Gloves);
	SwapCosmetic(C_Selected_Hair);
	SwapCosmetic(C_Selected_Head);
	SwapCosmetic(C_Selected_Shirt);
	SwapCosmetic(C_Selected_Pants);
	SwapCosmetic(C_Selected_Boots);
}

void UCustomizationComponent::TemporarilySwapCosmetics(UCosmeticInfo* CosmeticInfo)
{
	if (!PlayerRef) return;

	USkeletalMesh* NewMesh = CosmeticInfo->SkeletalMesh;
	
	switch (CosmeticInfo->CosmeticType)
	{
		case ECosmeticType::Boots:
			PlayerRef->SK_Boots_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Gloves:
			PlayerRef->SK_Gloves_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Head:
			PlayerRef->SK_Head_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Teeth:
			PlayerRef->SK_Teeth_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Beard:
			PlayerRef->SK_Beard_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Hair:
			PlayerRef->SK_Hair_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Eyebrows:
			PlayerRef->SK_Eyebrows_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Eyes:
			PlayerRef->SK_Eyes_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Shirt:
			PlayerRef->SK_Shirt_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Pants:
			PlayerRef->SK_Pants_Component->SetSkeletalMesh(NewMesh);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			break;
	}
}

void UCustomizationComponent::ResetCosmetic(ECosmeticType CosmeticType)
{
	if (!PlayerRef) return;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			PlayerRef->SK_Boots_Component->SetSkeletalMesh(C_Selected_Boots->SkeletalMesh);
			break;
		case ECosmeticType::Gloves:
			PlayerRef->SK_Gloves_Component->SetSkeletalMesh(C_Selected_Gloves->SkeletalMesh);
			break;
		case ECosmeticType::Head:
			PlayerRef->SK_Head_Component->SetSkeletalMesh(C_Selected_Head->SkeletalMesh);
			break;
		case ECosmeticType::Teeth:
			PlayerRef->SK_Teeth_Component->SetSkeletalMesh(C_Selected_Teeth->SkeletalMesh);
			break;
		case ECosmeticType::Beard:
			PlayerRef->SK_Beard_Component->SetSkeletalMesh(C_Selected_Beard->SkeletalMesh);
			break;
		case ECosmeticType::Hair:
			PlayerRef->SK_Hair_Component->SetSkeletalMesh(C_Selected_Hair->SkeletalMesh);
			break;
		case ECosmeticType::Eyebrows:
			PlayerRef->SK_Eyebrows_Component->SetSkeletalMesh(C_Selected_Eyebrows->SkeletalMesh);
			break;
		case ECosmeticType::Eyes:
			PlayerRef->SK_Eyes_Component->SetSkeletalMesh(C_Selected_Eyes->SkeletalMesh);
			break;
		case ECosmeticType::Shirt:
			PlayerRef->SK_Shirt_Component->SetSkeletalMesh(C_Selected_Shirt->SkeletalMesh);
			break;
		case ECosmeticType::Pants:
			PlayerRef->SK_Pants_Component->SetSkeletalMesh(C_Selected_Pants->SkeletalMesh);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			break;
	}
}

void UCustomizationComponent::SwapCosmetic(UCosmeticInfo* CosmeticInfo)
{
	if (!PlayerRef) return;

	USkeletalMesh* NewMesh = CosmeticInfo->SkeletalMesh;
	
	switch (CosmeticInfo->CosmeticType)
	{
		case ECosmeticType::Boots:
			C_Selected_Boots = CosmeticInfo;
			PlayerRef->SK_Boots_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Gloves:
			C_Selected_Gloves = CosmeticInfo;
			PlayerRef->SK_Gloves_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Head:
			C_Selected_Head = CosmeticInfo;
			PlayerRef->SK_Head_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Teeth:
			C_Selected_Teeth = CosmeticInfo;
			PlayerRef->SK_Teeth_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Beard:
			C_Selected_Beard = CosmeticInfo;
			PlayerRef->SK_Beard_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Hair:
			C_Selected_Hair = CosmeticInfo;
			PlayerRef->SK_Hair_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Eyebrows:
			C_Selected_Eyebrows = CosmeticInfo;
			PlayerRef->SK_Eyebrows_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Eyes:
			C_Selected_Eyes = CosmeticInfo;
			PlayerRef->SK_Eyes_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Shirt:
			C_Selected_Shirt = CosmeticInfo;
			PlayerRef->SK_Shirt_Component->SetSkeletalMesh(NewMesh);
			break;
		case ECosmeticType::Pants:
			C_Selected_Pants = CosmeticInfo;
			PlayerRef->SK_Pants_Component->SetSkeletalMesh(NewMesh);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			break;
	}
}

bool UCustomizationComponent::IsWearingCosmetic(UCosmeticInfo* CosmeticInfo)
{
	switch (CosmeticInfo->CosmeticType)
		{
		case ECosmeticType::Boots:
			if (CosmeticInfo == C_Selected_Boots) return true;
		case ECosmeticType::Gloves:
			if (CosmeticInfo == C_Selected_Gloves) return true;
		case ECosmeticType::Head:
			if (CosmeticInfo == C_Selected_Head) return true;
		case ECosmeticType::Teeth:
			if (CosmeticInfo == C_Selected_Teeth) return true;
		case ECosmeticType::Beard:
			if (CosmeticInfo == C_Selected_Beard) return true;
		case ECosmeticType::Hair:
			if (CosmeticInfo == C_Selected_Hair) return true;
		case ECosmeticType::Eyebrows:
			if (CosmeticInfo == C_Selected_Eyebrows) return true;
		case ECosmeticType::Eyes:
			if (CosmeticInfo == C_Selected_Eyes) return true;
		case ECosmeticType::Shirt:
			if (CosmeticInfo == C_Selected_Shirt) return true;
		case ECosmeticType::Pants:
			if (CosmeticInfo == C_Selected_Pants) return true;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			return false;
	}
}
