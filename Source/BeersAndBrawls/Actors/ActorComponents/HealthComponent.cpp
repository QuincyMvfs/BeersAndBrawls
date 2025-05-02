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

bool UHealthComponent::TakeDamage(float Damage, AActor* Instigator, AActor* Victim)
{
	if (!Damage) return false;

	M_CurrentHealth -= Damage;
	M_CurrentHealth = FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);
	
	OnDamageTakenEvent.Broadcast(Damage);
	if (M_CurrentHealth <= 0)
	{
		OnDeathEvent.Broadcast(Victim);
		return true;
	}

	return false;
}

void UHealthComponent::Heal(float HealAmount, AActor* Instigator, AActor* Victim)
{
	if (!HealAmount) return;

	M_CurrentHealth += HealAmount;
	M_CurrentHealth = FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);

	OnHealEvent.Broadcast(HealAmount);
}

void UHealthComponent::ResetCurrentHealth()
{
	M_CurrentHealth = M_MaxHealth;
}

void UHealthComponent::SetCurrentHealth(float NewCurrentHealth)
{
	M_CurrentHealth = NewCurrentHealth;
	M_CurrentHealth = FMath::Clamp(M_CurrentHealth, 0, M_MaxHealth);
	OnHealEvent.Broadcast(M_CurrentHealth);
}

void UHealthComponent::SetMaxHealth(float NewMaxHealth)
{
	M_MaxHealth = NewMaxHealth;
	M_CurrentHealth = M_MaxHealth;
	OnHealEvent.Broadcast(M_CurrentHealth);
}

void UHealthComponent::LevelUpMaxHealth(float Multiplier)
{
	M_MaxHealth *= Multiplier;
	M_MaxHealth = FMath::RoundToInt(M_MaxHealth);
	M_CurrentHealth = M_MaxHealth;
	OnHealEvent.Broadcast(M_CurrentHealth);
}

void UHealthComponent::AdjustDamageResistance(float Amount)
{
	float NewModifier = M_DamageResistance += Amount;
	M_DamageResistance = FMath::Clamp(NewModifier, 0.1f, 3.0f);
}

