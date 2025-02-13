// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Enums/EItemType.h"
#include "BeersAndBrawls/Enums/EPlayerInputState.h"
#include "BeersAndBrawls/Items/UItem.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	M_SelectedWeapon = M_DefaultSelectedWeapon;
	M_Items = M_DefaultItems;
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	M_SelectedWeapon = M_DefaultSelectedWeapon;
	M_Items = M_DefaultItems;
	AddItem(M_SelectedWeapon);
	
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void UInventoryComponent::EquipWeapon(UItem* ItemToEquip)
{
	M_SelectedWeapon = Cast<UWeapon>(ItemToEquip);
	
	if (!M_Items.Contains(ItemToEquip))	AddItem(ItemToEquip);
	
	if (PlayerRef)
	{
		UE_LOG(LogTemp, Warning, TEXT("VALID"));
		PlayerRef->DisplayNewWeaponMesh(EPlayerInputState::World);
	}
}

void UInventoryComponent::AddItem(UItem* ItemToAdd)
{
	M_Items.Add(ItemToAdd);
}

void UInventoryComponent::RemoveItem(UItem* ItemToRemove)
{
	if (M_Items.Contains(ItemToRemove))
	{
		M_Items.Remove(ItemToRemove);
		if (ItemToRemove == M_SelectedWeapon)
		{
			EquipWeapon(Cast<UWeapon>(M_Items[0]));	
		}
	}
}

bool UInventoryComponent::DoesPlayerHaveItem(UItem* ItemToCheck)
{
	for (UItem* Item : M_Items)
	{
		if (Item->ItemName.ToString() == ItemToCheck->ItemName.ToString()) return true;
	}

	return false;
}

bool UInventoryComponent::CanPlayerSellWeapon()
{
	int TotalWeapons = 0;
	for (const UItem* Item : M_Items)
	{
		if (Item->ItemType == EItemType::Blunt ||
			Item->ItemType == EItemType::Chop ||
			Item->ItemType == EItemType::Cut) TotalWeapons++;
	}

	if (TotalWeapons > 1) { return true; }
	else { return false; }
}



