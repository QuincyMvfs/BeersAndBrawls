// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EActiveUser.h"
#include "GameFramework/Actor.h"
#include "CombatManager.generated.h"

enum class EActiveUser : uint8;

UCLASS()
class BEERSANDBRAWLS_API ACombatManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACombatManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EActiveUser ActiveUser = EActiveUser::Player;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EActiveUser DuelWinner = EActiveUser::Player;
};