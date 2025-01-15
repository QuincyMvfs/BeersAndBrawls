// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDamageTaken, float, DamageTaken);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeal, float, HealthHealed);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, AActor*, Deceased);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintAssignable)
	FOnDamageTaken OnDamageTakenEvent;

	UPROPERTY(BlueprintAssignable)
	FOnHeal OnHealEvent;

	UPROPERTY(BlueprintAssignable)
	FOnDeath OnDeathEvent;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float Damage, AActor* Instigator, AActor* Victim);
	
	UFUNCTION(BlueprintCallable)
	void Heal(float HealAmount, AActor* Instigator, AActor* Victim);
	
	UFUNCTION(BlueprintCallable)
	void ResetCurrentHealth();
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentHealth(float NewCurrentHealth);

	UFUNCTION(BlueprintCallable)
	void SetMaxHealth(float NewMaxHealth);
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Health)
	float M_CurrentHealth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Health, meta = (UIMin = "0.0", UIMax = "500.0"))
	float M_MaxHealth = 100;
		
};
