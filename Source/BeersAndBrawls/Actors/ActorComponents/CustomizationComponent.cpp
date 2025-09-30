// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationComponent.h"

// Sets default values for this component's properties
UCustomizationComponent::UCustomizationComponent()
{
	
}


// Called when the game starts
void UCustomizationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UCustomizationComponent::SwapCosmetic(ECosmeticType CosmeticType, USkeletalMeshComponent* NewMesh)
{
	switch (CosmeticType)
	{
		case ECosmeticType::Boots:
			C_Selected_Boots = NewMesh;
			break;
		case ECosmeticType::Gloves:
			C_Selected_Gloves = NewMesh;
			break;
		case ECosmeticType::Head:
			C_Selected_Head = NewMesh;
			break;
		case ECosmeticType::Teeth:
			C_Selected_Teeth = NewMesh;
			break;
		case ECosmeticType::Beard:
			C_Selected_Beard = NewMesh;
			break;
		case ECosmeticType::Hair:
			C_Selected_Hair = NewMesh;
			break;
		case ECosmeticType::Eyebrows:
			C_Selected_Eyebrows = NewMesh;
			break;
		case ECosmeticType::Shirt:
			C_Selected_Shirt = NewMesh;
			break;
		case ECosmeticType::Pants:
			C_Selected_Pants = NewMesh;
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Component: Invalid CosmeticType"));
			break;
	}
}