// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LevelingComponent.generated.h"


class UAbilityInfo;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API ULevelingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULevelingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> LockedAbilities;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<UAbilityInfo*> UnlockedAbilities;

		
};
