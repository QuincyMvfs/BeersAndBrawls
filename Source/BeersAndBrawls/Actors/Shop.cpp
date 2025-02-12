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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Hello, UE5!"));
	UE_LOG(LogTemp, Warning, TEXT("NO PLAYER"));
	
	if (PlayerRef && M_ItemsForSale.Num() > 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO ITEMS"));
		if (PlayerRef->CurrencyComponent->M_TotalBeerBux >= ItemToBuy->Cost)
		{
			PlayerRef->CurrencyComponent->RemoveBeerBux(ItemToBuy->Cost);
			PlayerRef->InventoryComponent->EquipWeapon(ItemToBuy);
			UE_LOG(LogTemp, Warning, TEXT("CAN BUY"))
			return true;
		}
	}

	return false;
}

bool AShop::SellItem(UItem* ItemToSell)
{
	if (PlayerRef->InventoryComponent->DoesPlayerHaveItem(ItemToSell))
	{
		PlayerRef->CurrencyComponent->AddBeerBux(PlayerRef->InventoryComponent->M_SelectedWeapon->Cost);
		PlayerRef->InventoryComponent->RemoveItem(ItemToSell);
		UE_LOG(LogTemp, Warning, TEXT("CAN SELL"))

		return true;
	}

	return false;
}

