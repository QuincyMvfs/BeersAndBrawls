// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

class UInventoryComponent;
class UHealthComponent;
class UCombatComponent;

UCLASS()
class BEERSANDBRAWLS_API AEnemy : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemy();

	// Custom Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* InventoryComponent;

	// Mesh Slots
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshs", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Meshs", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SkeletalMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void StartGivingInputs();
	void SendInput();
	int InputIndex = 0;

};
