// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UItem.generated.h"

class ABeersAndBrawlsCharacter;

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class BEERSANDBRAWLS_API UItem : public UObject
{
	GENERATED_BODY()
	
public:

	virtual void Use(ABeersAndBrawlsCharacter* OwningCharacter);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(ABeersAndBrawlsCharacter* OwningCharacter);
};
