// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FBoneSizes.h"
#include "Components/ActorComponent.h"
#include "CustomizationComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UCustomizationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCustomizationComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Body Size Changes")
	FBoneSizes M_BoneSizes;
		
};
