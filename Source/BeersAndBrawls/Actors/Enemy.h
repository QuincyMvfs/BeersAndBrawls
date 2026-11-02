// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BeersAndBrawls/Enums/ECosmeticType.h"
#include "BeersAndBrawls/Structs/FCombatPatterns.h"
#include "BeersAndBrawls/Structs/FEnemyInfoStruct.h"
#include "BeersAndBrawls/Structs/FLootInfo.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Enemy.generated.h"

class ABeersAndBrawlsCharacter;
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

	// Customization Mesh's
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Boots_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Gloves_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Head_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Teeth_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Beard_Component;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Hair_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Eyes_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Eyebrows_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Shirt_Component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USkeletalMeshComponent* SK_Pants_Component;
	
	// Selected Cosmetics
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Boots;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Gloves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Head;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Teeth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Beard;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Hair;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Eyes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Eyebrows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Shirt;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UCosmeticInfo* C_Selected_Pants;
	
	// Mesh Slots
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Meshs", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* EquippedWeaponComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	void InitializeEnemy(FEnemyInfoStruct NewEnemyInfo);

	// Generates all skeletal mesh components used in customization
	void SetupCustomizationMeshs();
	
	UFUNCTION(BlueprintCallable)
	void StartSendingCombatInputs(FCombatPatterns Pattern, bool IsDefending);

	UFUNCTION(BlueprintCallable)
	void StopSendingInputs();
	
	UFUNCTION(BlueprintCallable)
	UAbilityInfo* GenerateRandomAbility();

	void UpdateCosmetics();
	void UpdateCosmeticColors(UCosmeticInfo* CosmeticInfo);
	
	void ChangeColor(USkeletalMeshComponent* SkeletalMeshComponent, USkeletalMeshComponent* SkeletalMeshComponent2, 
	int ElementIndex, FLinearColor NewColor, UCosmeticInfo* CosmeticInfo);
	//
	
	void SendInput();
	int InputIndex = 0;
	FTimerHandle AttackLoop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsDead = false;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FEnemyInfoStruct EnemyInfo;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	ABeersAndBrawlsCharacter* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Customization Cosmetics")
	UMaterialInterface* CustomMaterial;

};
