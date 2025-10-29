// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Enums/ECosmeticType.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "BeersAndBrawlsCharacter.generated.h"

class UCosmeticInfo;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CustomizationCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* EnemySelectorCamera;
	
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

	// Customization Mesh's
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Customization Skeletal Mesh Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* CustomizationRoot;
	
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

	// Events
	UPROPERTY(BlueprintAssignable)
	FOnTurnChanged OnTurnChangedEvent;
	
/// Public Functions
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// Generates all default values in Constructor
	void SetupDefaults();

	// Generates all skeletal mesh components used in customization
	void SetupCustomizationMeshs();

	// Attempts interact
	void TryInteract();

	// Displays weapon mesh is correct socket when the players state is changed (world, combat)
	void DisplayNewWeaponMesh(EPlayerInputState NewState);

	// Displays consumable's mesh
	void DisplayNewConsumableMesh();
	
	// Swaps the camera to the given index (can be made better)
	UFUNCTION(BlueprintCallable)
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanMove = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
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

