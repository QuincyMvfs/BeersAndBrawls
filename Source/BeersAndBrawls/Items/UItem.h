// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.generated.h"

class UAbilityInfo;
enum class EItemType;
class ABeersAndBrawlsCharacter;

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class BEERSANDBRAWLS_API UItem : public UObject
{
	GENERATED_BODY()
	
public:

	virtual void Use(ABeersAndBrawlsCharacter* OwningCharacter);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(ABeersAndBrawlsCharacter* OwningCharacter);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ItemDescription;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	EItemType ItemType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Cost;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> Abilities;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UStaticMesh* ItemMesh;
};
