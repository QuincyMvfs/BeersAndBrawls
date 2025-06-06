// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

#include "LevelingComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Enums/EItemType.h"
#include "BeersAndBrawls/Enums/EPlayerInputState.h"
#include "BeersAndBrawls/Items/Consumable.h"
#include "BeersAndBrawls/Items/UItem.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	for (UItem* Item : M_DefaultItems) { AddItem(Item); }
	
	EquipWeapon(M_DefaultSelectedWeapon);

}

void UInventoryComponent::EquipWeapon(UItem* WeaponToEquip)
{
	M_SelectedWeapon = Cast<UWeapon>(WeaponToEquip);
	
	if (!M_Items.Contains(WeaponToEquip)) AddItem(WeaponToEquip);
	
	if (PlayerRef)
	{
		OnNewItemEquippedEvent.Broadcast(WeaponToEquip);
		PlayerRef->LevelingComponent->UpdateAllAbilities();
		PlayerRef->DisplayNewWeaponMesh(EPlayerInputState::World);
	}
}

void UInventoryComponent::EquipConsumable(UItem* ConsumableToEquip)
{
	M_SelectedConsumable = Cast<UConsumable>(ConsumableToEquip);
	
	if (!M_Items.Contains(ConsumableToEquip)) AddItem(ConsumableToEquip);
	
	if (PlayerRef)
	{
		OnNewItemEquippedEvent.Broadcast(ConsumableToEquip);
		PlayerRef->LevelingComponent->UpdateAllAbilities();
		PlayerRef->DisplayNewConsumableMesh();
	}
}

void UInventoryComponent::AddItem(UItem* ItemToAdd)
{
	M_Items.Add(ItemToAdd);
	OnItemAddedEvent.Broadcast(ItemToAdd);
}

void UInventoryComponent::RemoveItem(UItem* ItemToRemove)
{
	if (M_Items.Contains(ItemToRemove))
	{
		M_Items.Remove(ItemToRemove);
		OnItemRemovedEvent.Broadcast(ItemToRemove);
		if (ItemToRemove == M_SelectedWeapon)
		{
			if (M_Items[0])
			{
				EquipWeapon(Cast<UWeapon>(M_Items[0]));
			}
			else { M_SelectedWeapon = nullptr; }
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
	if (M_Items.Num() <= 0) return false;
	
	for (const UItem* Item : M_Items)
	{
		if (Item->ItemType == EItemType::Blunt||
			Item->ItemType == EItemType::Chop ||
			Item->ItemType == EItemType::Cut) TotalWeapons++;
	}

	if (TotalWeapons > 1) { return true; }

	return false;
}

bool UInventoryComponent::CanPlayerSellConsumable()
{
	int TotalConsumables = 0;
	if (M_Items.Num() <= 0) return false;
	
	for (const UItem* Item : M_Items)
	{
		if (Item->ItemType == EItemType::Consumable) TotalConsumables++;
	}

	if (TotalConsumables > 1) { return true; }

	return false;
}



