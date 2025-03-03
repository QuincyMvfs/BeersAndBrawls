// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "ActorComponents/CurrencyComponent.h"
#include "ActorComponents/InventoryComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Enums/EItemType.h"
#include "BeersAndBrawls/Enums/EPlayerInputState.h"
#include "BeersAndBrawls/Items/Consumable.h"
#include "BeersAndBrawls/Items/UItem.h"
#include "BeersAndBrawls/Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AShop::AShop()
{
 	M_ItemsForSale = M_DefaultItemsForSale;
}

// Called when the game starts or when spawned
void AShop::BeginPlay()
{
	Super::BeginPlay();
	M_ItemsForSale = M_DefaultItemsForSale;
	PlayerRef = Cast<ABeersAndBrawlsCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

bool AShop::BuyItem(UItem* ItemToBuy)
{
	if (PlayerRef && M_ItemsForSale.Num() > 0)
	{
		if (CanBuyItem(ItemToBuy))
		{
			PlayerRef->CurrencyComponent->RemoveBeerBux(ItemToBuy->Cost);
			if (ItemToBuy->ItemType == EItemType::Consumable)
			{
				PlayerRef->InventoryComponent->EquipConsumable(ItemToBuy);
			}
			else
			{
				PlayerRef->InventoryComponent->EquipWeapon(ItemToBuy);
			}
			return true;
		}
	}

	return false;
}

bool AShop::SellItem(UItem* ItemToSell)
{
	if (CanSellItem(ItemToSell))
	{
		PlayerRef->CurrencyComponent->AddBeerBux(ItemToSell->Cost);
		PlayerRef->InventoryComponent->RemoveItem(ItemToSell);

		return true;
	}

	return false;
	//
}

bool AShop::CanBuyItem(UItem* ItemToBuy)
{
	if (PlayerRef->CurrencyComponent->M_TotalBeerBux >= ItemToBuy->Cost) return true;

	return false;
}

bool AShop::CanSellItem(UItem* ItemToSell)
{
	if (PlayerRef->InventoryComponent->DoesPlayerHaveItem(ItemToSell))
	{
		if (ItemToSell->ItemType == EItemType::Consumable)
		{
			UConsumable* ConsumableToSell = Cast<UConsumable>(ItemToSell);
			if (PlayerRef->InventoryComponent->CanPlayerSellConsumable() &&
			ConsumableToSell != PlayerRef->InventoryComponent->M_SelectedConsumable) { return true; }
		}
		else
		{
			if (PlayerRef->InventoryComponent->CanPlayerSellWeapon() &&
			ItemToSell != PlayerRef->InventoryComponent->M_SelectedWeapon) { return true; }
		}
	}

	return false;
}

