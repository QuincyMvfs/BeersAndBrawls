// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


struct FCombatPatterns;
enum class ECombatKey : uint8;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void SetCombatPattern(FCombatPatterns NewCombatPattern);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FCombatPatterns M_SelectedCombatPattern;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool M_CanReceiveInputs = false;
};