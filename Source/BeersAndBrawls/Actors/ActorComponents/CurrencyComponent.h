// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CurrencyComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeerBuxAdded, int, AmountAdded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBeerBuxRemoved, int, AmountRemoved);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UCurrencyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCurrencyComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable)
	FOnBeerBuxAdded OnBeerBuxAddedEvent;

	UPROPERTY(BlueprintAssignable)
	FOnBeerBuxRemoved OnBeerBuxRemovedEvent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_TotalBeerBux = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int M_MaxBeerBux = 9999999;

	UFUNCTION(BlueprintCallable)
	void AddBeerBux(int AmountToAdd);

	UFUNCTION(BlueprintCallable)
	void RemoveBeerBux(int AmountToRemove);
};
