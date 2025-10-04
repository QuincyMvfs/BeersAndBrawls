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
	SwapCosmetic(C_Selected_Teeth);
	
	CosmeticColors.Add(C_Selected_Boots->DefaultColor);
	CosmeticColors.Add(C_Selected_Gloves->DefaultColor);
	CosmeticColors.Add(C_Selected_Head->DefaultColor);
	CosmeticColors.Add(C_Selected_Teeth->DefaultColor);
	CosmeticColors.Add(C_Selected_Beard->DefaultColor);
	CosmeticColors.Add(C_Selected_Hair->DefaultColor);
	CosmeticColors.Add(C_Selected_Eyebrows->DefaultColor);
	CosmeticColors.Add(C_Selected_Eyes->DefaultColor);
	CosmeticColors.Add(C_Selected_Shirt->DefaultColor);
	CosmeticColors.Add(C_Selected_Pants->DefaultColor);
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

void UCustomizationComponent::ChangeCosmeticColor(ECosmeticType CosmeticType, FLinearColor NewColor)
{
	if (!PlayerRef) return;

	USkeletalMeshComponent* SkeletalMeshComponent;
	USkeletalMeshComponent* SkeletalMeshComponent2 = nullptr;
	int ElementIndex = 0;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			SkeletalMeshComponent = PlayerRef->SK_Boots_Component;
			CosmeticColors [0] = NewColor;
			break;
		case ECosmeticType::Gloves:
			SkeletalMeshComponent = PlayerRef->SK_Gloves_Component;
			CosmeticColors [1] = NewColor;
			break;
		case ECosmeticType::Head:
			SkeletalMeshComponent = PlayerRef->SK_Head_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			CosmeticColors [2] = NewColor;
			break;
		case ECosmeticType::Teeth:
			SkeletalMeshComponent = PlayerRef->SK_Teeth_Component;
			CosmeticColors [3] = NewColor;
			break;
		case ECosmeticType::Beard:
			SkeletalMeshComponent = PlayerRef->SK_Beard_Component;
			CosmeticColors [4] = NewColor;
			break;
		case ECosmeticType::Hair:
			SkeletalMeshComponent = PlayerRef->SK_Hair_Component;
			CosmeticColors [5] = NewColor;
			break;
		case ECosmeticType::Eyebrows:
			SkeletalMeshComponent = PlayerRef->SK_Eyebrows_Component;
			CosmeticColors [6] = NewColor;
			break;
		case ECosmeticType::Eyes:
			SkeletalMeshComponent = PlayerRef->SK_Eyes_Component;
			ElementIndex = 2;
			CosmeticColors [7] = NewColor;
			break;
		case ECosmeticType::Shirt:
			SkeletalMeshComponent = PlayerRef->SK_Shirt_Component;
			CosmeticColors [8] = NewColor;
			break;
		case ECosmeticType::Pants:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			CosmeticColors [9] = NewColor;
			break;
		default:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			CosmeticColors [9] = NewColor;
			break;
	}

	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(CustomMaterial, PlayerRef);
	SkeletalMeshComponent->SetMaterial(ElementIndex, DynamicMaterial);
	if (SkeletalMeshComponent2) { SkeletalMeshComponent2->SetMaterial(ElementIndex, DynamicMaterial); }
	
	DynamicMaterial->SetVectorParameterValue("Color", NewColor);
}

void UCustomizationComponent::TemporarilyChangeCosmeticColor(ECosmeticType CosmeticType, FLinearColor GivenColor)
{
	if (!PlayerRef) return;

	USkeletalMeshComponent* SkeletalMeshComponent;
	USkeletalMeshComponent* SkeletalMeshComponent2 = nullptr;
	int ElementIndex = 0;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			SkeletalMeshComponent = PlayerRef->SK_Boots_Component;
			break;
		case ECosmeticType::Gloves:
			SkeletalMeshComponent = PlayerRef->SK_Gloves_Component;
			break;
		case ECosmeticType::Head:
			SkeletalMeshComponent = PlayerRef->SK_Head_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			break;
		case ECosmeticType::Teeth:
			SkeletalMeshComponent = PlayerRef->SK_Teeth_Component;
			break;
		case ECosmeticType::Beard:
			SkeletalMeshComponent = PlayerRef->SK_Beard_Component;
			break;
		case ECosmeticType::Hair:
			SkeletalMeshComponent = PlayerRef->SK_Hair_Component;
			break;
		case ECosmeticType::Eyebrows:
			SkeletalMeshComponent = PlayerRef->SK_Eyebrows_Component;
			break;
		case ECosmeticType::Eyes:
			SkeletalMeshComponent = PlayerRef->SK_Eyes_Component;
			ElementIndex = 2;
			break;
		case ECosmeticType::Shirt:
			SkeletalMeshComponent = PlayerRef->SK_Shirt_Component;
			break;
		case ECosmeticType::Pants:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			break;
		default:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			break;
	}
	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(CustomMaterial, PlayerRef);
	SkeletalMeshComponent->SetMaterial(ElementIndex, DynamicMaterial);
	if (SkeletalMeshComponent2) { SkeletalMeshComponent2->SetMaterial(ElementIndex, DynamicMaterial); }
	
	DynamicMaterial->SetVectorParameterValue("Color", GivenColor);
}

void UCustomizationComponent::ResetCosmeticColor(ECosmeticType CosmeticType)
{
	if (!PlayerRef) return;

	USkeletalMeshComponent* SkeletalMeshComponent;
	USkeletalMeshComponent* SkeletalMeshComponent2 = nullptr;
	FLinearColor OriginalColor;
	int ElementIndex = 0;
	
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			SkeletalMeshComponent = PlayerRef->SK_Boots_Component;
			OriginalColor = CosmeticColors [0];
			break;
		case ECosmeticType::Gloves:
			SkeletalMeshComponent = PlayerRef->SK_Gloves_Component;
			OriginalColor = CosmeticColors [1];
			break;
		case ECosmeticType::Head:
			SkeletalMeshComponent = PlayerRef->SK_Head_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			OriginalColor = CosmeticColors [2];
			break;
		case ECosmeticType::Teeth:
			SkeletalMeshComponent = PlayerRef->SK_Teeth_Component;
			OriginalColor = CosmeticColors [3];
			break;
		case ECosmeticType::Beard:
			SkeletalMeshComponent = PlayerRef->SK_Beard_Component;
			OriginalColor = CosmeticColors [4];
			break;
		case ECosmeticType::Hair:
			SkeletalMeshComponent = PlayerRef->SK_Hair_Component;
			OriginalColor = CosmeticColors [5];
			break;
		case ECosmeticType::Eyebrows:
			SkeletalMeshComponent = PlayerRef->SK_Eyebrows_Component;
			OriginalColor = CosmeticColors [6];
			break;
		case ECosmeticType::Eyes:
			SkeletalMeshComponent = PlayerRef->SK_Eyes_Component;
			ElementIndex = 2;
			OriginalColor = CosmeticColors [7];
			break;
		case ECosmeticType::Shirt:
			SkeletalMeshComponent = PlayerRef->SK_Shirt_Component;
			OriginalColor = CosmeticColors [8];
			break;
		case ECosmeticType::Pants:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			OriginalColor = CosmeticColors [9];
			break;
		default:
			SkeletalMeshComponent = PlayerRef->SK_Pants_Component;
			SkeletalMeshComponent2 = PlayerRef->GetMesh();
			OriginalColor = CosmeticColors [9];
			break;
	}

	
	UMaterialInstanceDynamic* DynamicMaterial = UMaterialInstanceDynamic::Create(CustomMaterial, PlayerRef);
	SkeletalMeshComponent->SetMaterial(ElementIndex, DynamicMaterial);
	if (SkeletalMeshComponent2) { SkeletalMeshComponent2->SetMaterial(ElementIndex, DynamicMaterial); }
	
	DynamicMaterial->SetVectorParameterValue("Color", OriginalColor);
}

FLinearColor UCustomizationComponent::GetSelectedCosmeticColor(ECosmeticType CosmeticType)
{
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			return CosmeticColors[0];
		case ECosmeticType::Gloves:
			return CosmeticColors[1];
		case ECosmeticType::Head:
			return CosmeticColors[2];
		case ECosmeticType::Teeth:
			return CosmeticColors[3];
		case ECosmeticType::Beard:
			return CosmeticColors[4];
		case ECosmeticType::Hair:
			return CosmeticColors[5];
		case ECosmeticType::Eyebrows:
			return CosmeticColors[6];
		case ECosmeticType::Eyes:
			return CosmeticColors[7];
		case ECosmeticType::Shirt:
			return CosmeticColors[8];
		case ECosmeticType::Pants:
			return CosmeticColors[9];
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			return CosmeticColors[0];
	}
}
