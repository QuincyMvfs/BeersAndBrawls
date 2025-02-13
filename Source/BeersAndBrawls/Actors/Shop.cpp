// Fill out your copyright notice in the Description page of Project Settings.


#include "Shop.h"

#include "ActorComponents/CurrencyComponent.h"
#include "ActorComponents/InventoryComponent.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"
#include "BeersAndBrawls/Enums/EPlayerInputState.h"
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
			PlayerRef->InventoryComponent->EquipWeapon(ItemToBuy);
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
}

bool AShop::CanBuyItem(UItem* ItemToBuy)
{
	if (PlayerRef->CurrencyComponent->M_TotalBeerBux >= ItemToBuy->Cost) return true;

	return false;
}

bool AShop::CanSellItem(UItem* ItemToSell)
{
	if (PlayerRef->InventoryComponent->DoesPlayerHaveItem(ItemToSell) &&
		PlayerRef->InventoryComponent->CanPlayerSellWeapon() &&
		ItemToSell != PlayerRef->InventoryComponent->M_SelectedWeapon) { return true; }

	return false;
}

