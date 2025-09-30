// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationShop.h"

// Sets default values
ACustomizationShop::ACustomizationShop()
{
 	

}

// Called when the game starts or when spawned
void ACustomizationShop::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACustomizationShop::UnlockCosmetic(ECosmeticType Type, UCosmeticInfo* NewMeshInfo)
{
	switch (Type)
	{
		case ECosmeticType::Boots:
			Unlocked_Boots.Add(NewMeshInfo);
			Locked_Boots.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Gloves:
			Unlocked_Gloves.Add(NewMeshInfo);
			Locked_Gloves.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Head:
			Unlocked_Heads.Add(NewMeshInfo);
			Locked_Heads.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Teeth:
			Unlocked_Teeth.Add(NewMeshInfo);
			Locked_Teeth.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Beard:
			Unlocked_Beards.Add(NewMeshInfo);
			Locked_Beards.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Hair:
			Unlocked_Hair.Add(NewMeshInfo);
			Locked_Hair.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Eyebrows:
			Unlocked_Eyebrows.Add(NewMeshInfo);
			Locked_Eyebrows.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Shirt:
			Unlocked_Shirts.Add(NewMeshInfo);
			Locked_Shirts.Remove(NewMeshInfo);
			break;
		case ECosmeticType::Pants:
			Unlocked_Pants.Add(NewMeshInfo);
			Locked_Pants.Remove(NewMeshInfo);
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Shop: Invalid CosmeticType"));
			break;
	}

	OnCosmeticUnlockedEvent.Broadcast(Type, NewMeshInfo);
}



