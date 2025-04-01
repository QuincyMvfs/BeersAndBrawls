// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class UStatusEffectComponent;
class UAbilityInfo;
struct FEnemyInfoStruct;
class UInventoryComponent;
class UHealthComponent;
class UCombatComponent;

UCLASS()
class BEERSANDBRAWLS_API AEnemy : public ACharacter
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStatusEffectComponent* StatusEffectComponent;

	// Mesh Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshs", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedWeaponComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void InitializeEnemy(FEnemyInfoStruct NewEnemyInfo);

	UFUNCTION(BlueprintCallable)
	void StartSendingCombatInputs(FCombatPatterns Pattern, bool IsDefending);

	UFUNCTION(BlueprintCallable)
	void StopSendingInputs();
	
	UFUNCTION(BlueprintCallable)
	UAbilityInfo* GenerateRandomAbility();
	
	void SendInput();
	int InputIndex = 0;
	FTimerHandle AttackLoop;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FEnemyInfoStruct EnemyInfo;

};
