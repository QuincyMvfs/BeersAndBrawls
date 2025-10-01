// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomizationShop.h"

#include "BeersAndBrawls/DataAssets/CosmeticInfo.h"

// Sets default values
ACustomizationShop::ACustomizationShop()
{
 	

}

// Called when the game starts or when spawned
void ACustomizationShop::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACustomizationShop::UnlockCosmetic(UCosmeticInfo* NewMeshInfo)
{
	switch (NewMeshInfo->CosmeticType)
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
		case ECosmeticType::Eyes:
			Unlocked_Eyes.Add(NewMeshInfo);
			Locked_Eyes.Remove(NewMeshInfo);
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

	OnCosmeticUnlockedEvent.Broadcast(NewMeshInfo->CosmeticType, NewMeshInfo);
}

void ACustomizationShop::GetCosmetics(ECosmeticType Type, TArray<UCosmeticInfo*>& UnlockedCosmetics,
	TArray<UCosmeticInfo*>& LockedCosmetics)
{
	switch (Type)
	{
		case ECosmeticType::Boots:
			UnlockedCosmetics = Unlocked_Boots;
			LockedCosmetics = Locked_Boots;
			break;
		case ECosmeticType::Gloves:
			UnlockedCosmetics = Unlocked_Gloves;
			LockedCosmetics = Locked_Gloves;
			break;
		case ECosmeticType::Head:
			UnlockedCosmetics = Unlocked_Heads;
			LockedCosmetics = Locked_Heads;
			break;
		case ECosmeticType::Teeth:
			UnlockedCosmetics = Unlocked_Teeth;
			LockedCosmetics = Locked_Teeth;
			break;
		case ECosmeticType::Beard:
			UnlockedCosmetics = Unlocked_Beards;
			LockedCosmetics = Locked_Beards;
			break;
		case ECosmeticType::Hair:
			UnlockedCosmetics = Unlocked_Hair;
			LockedCosmetics = Locked_Hair;
			break;
		case ECosmeticType::Eyebrows:
			UnlockedCosmetics = Unlocked_Eyebrows;
			LockedCosmetics = Locked_Eyebrows;
			break;
		case ECosmeticType::Eyes:
			UnlockedCosmetics = Unlocked_Eyes;
			LockedCosmetics = Locked_Eyes;
			break;
		case ECosmeticType::Shirt:
			UnlockedCosmetics = Unlocked_Shirts;
			LockedCosmetics = Locked_Shirts;
			break;
		case ECosmeticType::Pants:
			UnlockedCosmetics = Unlocked_Pants;
			LockedCosmetics = Locked_Pants;
			break;
		default:
			UE_LOG(LogTemp, Error, TEXT("Customization Shop: Invalid CosmeticType"));
			break;
	}
}

bool ACustomizationShop::IsCosmeticUnlocked(UCosmeticInfo* CosmeticInfo)
{
	switch (CosmeticInfo->CosmeticType)
	{
		case ECosmeticType::Boots:
			if (Unlocked_Boots.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Gloves:
			if (Unlocked_Gloves.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Head:
			if (Unlocked_Heads.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Teeth:
			if (Unlocked_Teeth.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Beard:
			if (Unlocked_Beards.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Hair:
			if (Unlocked_Hair.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Eyes:
			if (Unlocked_Eyes.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Shirt:
			if (Unlocked_Shirts.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Pants:
			if (Unlocked_Pants.Contains(CosmeticInfo)) return true;
		case ECosmeticType::Eyebrows:
			if (Unlocked_Eyebrows.Contains(CosmeticInfo)) return true;
		default:
		 return false;
		
	}
}



