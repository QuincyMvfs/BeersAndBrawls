// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	M_CurrentHealth = M_MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	M_CurrentHealth = M_MaxHealth;
}

void UHealthComponent::TakeDamage(float Damage, AActor* Instigator, AActor* Victim)
{
	if (!Damage) return;

	M_CurrentHealth -= Damage;
	FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);
	
	OnDamageTakenEvent.Broadcast(Damage);
	if (M_CurrentHealth <= 0) OnDeathEvent.Broadcast(Victim);
}

void UHealthComponent::Heal(float HealAmount, AActor* Instigator, AActor* Victim)
{
	if (!HealAmount) return;

	M_CurrentHealth += HealAmount;
	FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);

	OnHealEvent.Broadcast(HealAmount);
}

void UHealthComponent::ResetCurrentHealth()
{
	M_CurrentHealth = M_MaxHealth;
}

void UHealthComponent::SetCurrentHealth(float NewCurrentHealth)
{
	M_CurrentHealth = NewCurrentHealth;
	FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);
}

