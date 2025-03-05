// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EActiveUser.h"
#include "BeersAndBrawls/Enums/EStatusEffectTypes.h"
#include "Components/ActorComponent.h"
#include "StatusEffectComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UStatusEffectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatusEffectComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	bool TriggerStatusEffect(TArray<EStatusEffectTypes> StatusEffects, EActiveUser Instigator);
		
};
