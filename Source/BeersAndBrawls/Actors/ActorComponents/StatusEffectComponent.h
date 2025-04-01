// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/EActiveUser.h"
#include "BeersAndBrawls/Enums/EStatusEffectTypes.h"
#include "BeersAndBrawls/Structs/FStatusEffect.h"
#include "Components/ActorComponent.h"
#include "StatusEffectComponent.generated.h"


struct FStatusEffectWithCounter;
struct FStatusEffect;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BEERSANDBRAWLS_API UStatusEffectComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatusEffectComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (Category = "Getters"))
	TArray<FStatusEffectWithCounter> ActiveStatusEffects;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	//* Variables
	/// Dazed Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Dazed Variables"))
	TArray<float> Dazed_InputsIncreasePercent {
		0.2f, 0.4f, 0.6f, 0.8f, 1.0f, 1.4f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Dazed Variables"))
	TArray<int> Dazed_EffectDuration {
		2, 2, 3, 3, 3, 2
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Dazed Variables"))
	TArray<float> Dazed_ChanceToTrigger {
		0.1f, 0.2f, 0.25f, 0.35f, 0.45f, 0.65f
	};

	/// Electrocuted Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Electrocuted Variables"))
	TArray<float> Electrocuted_InterruptionDelayGap {
		1.4f, 1.2f, 1.1f, 1.0f, 0.5f, 0.3f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Electrocuted Variables"))
	TArray<float> Electrocuted_InterruptionDelay {
		0.1f, 0.15f, 0.2f, 0.25f, 0.25f, 0.1f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Electrocuted Variables"))
	TArray<float> Electrocuted_ChanceToTrigger {
		0.1f, 0.2f, 0.25f, 0.35f, 0.45f, 0.65f
	};

	/// Inflamed Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Inflamed Variables"))
	TArray<float> Inflamed_DamagePercent {
		0.05f, 0.05f, 0.1f, 0.12f, 0.15f, 0.25f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Inflamed Variables"))
	TArray<int> Inflamed_EffectDuration {
		2, 3, 5, 5, 4, 3
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Inflamed Variables"))
	TArray<float> Inflamed_ChanceToTrigger {
		0.1f, 0.2f, 0.25f, 0.3f, 0.4f, 0.45f
	};

	/// Frozen Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Frozen Variables"))
	TArray<int> Frozen_EffectDuration {
		1, 1, 1, 2, 2, 3
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Frozen Variables"))
	TArray<float> Frozen_ChanceToTrigger {
		0.1f, 0.2f, 0.30f, 0.30f, 0.55f, 0.75f
	};

	/// Intoxicated Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Intoxicated Variables"))
	TArray<int> Intoxicated_EffectDuration {
		1, 1, 1, 1, 1, 2
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Intoxicated Variables"))
	TArray<float> Intoxicated_ModifierEffect {
		0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f
	};

	/// Weakened Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Weakened Variables"))
	TArray<float> Weakened_EffectModifier {
		0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.75f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Weakened Variables"))
	TArray<int> Weakened_EffectDuration {
		1, 1, 2, 2, 2, 3
	};

	/// Invigorated Variables
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Invigorated Variables"))
	TArray<float> Invigorated_EffectModifier {
		0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.75f
	};
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (Category = "Status Effect Variables|Invigorated Variables"))
	TArray<int> Invigorated_EffectDuration {
		2, 2, 3, 3, 4, 4
	};
	//*
	
	//* Functions
	// Trigger Status Effect Functions
	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Trigger Status Effect", Tooptip = "Triggers a Status Effect", Category = "StatusEffects"))
	bool TriggerStatusEffect(TArray<FStatusEffect> StatusEffects,
	UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);


	// Status Effect Functions
	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Daze(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);

	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Electrocute(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);
	
	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Inflamed(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);

	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Frozen(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);

	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Intoxicated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);

	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Weaken(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);

	UFUNCTION(BlueprintCallable, meta = (Category = "StatusEffects"))
	bool Trigger_Invigorated(int EffectTier, UStatusEffectComponent* Instigator, UStatusEffectComponent* Victim);
};
