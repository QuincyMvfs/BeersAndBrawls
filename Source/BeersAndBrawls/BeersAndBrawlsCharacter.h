// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "BeersAndBrawlsCharacter.generated.h"

class UCustomizationComponent;
class UStatusEffectComponent;
enum class EPlayerInputState : uint8;
class ULevelingComponent;
class UInventoryComponent;
class UHealthComponent;
class UCurrencyComponent;
class UCombatComponent;
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTurnChanged);

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ABeersAndBrawlsCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ABeersAndBrawlsCharacter();

/// Default Subobjects
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CombatCamera;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UCombatComponent* CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UCurrencyComponent* CurrencyComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* InventoryComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	ULevelingComponent* LevelingComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStatusEffectComponent* StatusEffectComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UCustomizationComponent* CustomizationComponent;

	// Weapon Mesh Slots
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponEquippedStaticMeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* WeaponBackSlotStaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ConsumableSlotStaticMeshComponent;

	UPROPERTY(BlueprintAssignable)
	FOnTurnChanged OnTurnChangedEvent;
	
/// Public Functions
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void SetupDefaults();

	void TryInteract();
	
	void DisplayNewWeaponMesh(EPlayerInputState NewState);

	void DisplayNewConsumableMesh();

	void SwapCameras(int Index);

	UFUNCTION(BlueprintCallable)
	void SetCanSelectAbility(bool Value);
protected:
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	bool CanMove = true;
	int ActiveCameraIndex = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool CanSelectAbility = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float M_DamageMultiplier = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float M_CombatSpeedMultiplier = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float M_CounterSpeedMultiplier = 1.0f;
};

