#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "FLootInfo.generated.h"

class UConsumable;
class UCosmeticInfo;
class UWeapon;

USTRUCT(BlueprintType)
struct FLootInfo
{
	GENERATED_BODY();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UCosmeticInfo*> Lootable_Cosmetics;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<ECosmeticType, FLinearColor> Lootable_Cosmetic_Colors;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UWeapon*> Lootable_Weapons;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UConsumable*> Lootable_Consumables;
	
};
