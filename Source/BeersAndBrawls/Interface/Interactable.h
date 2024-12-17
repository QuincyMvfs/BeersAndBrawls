// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

class ABeersAndBrawlsCharacter;
class ABeersAndBrawlsPlayerController;

UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class BEERSANDBRAWLS_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interactable")
	void Interact(ABeersAndBrawlsPlayerController* PlayerController, ABeersAndBrawlsCharacter* PlayerActor);

	virtual void Interact_Implementation(ABeersAndBrawlsPlayerController* PlayerController, ABeersAndBrawlsCharacter* PlayerActor);
	
};
