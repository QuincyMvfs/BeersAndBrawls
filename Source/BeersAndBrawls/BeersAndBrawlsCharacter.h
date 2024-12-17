// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "BeersAndBrawlsCharacter.generated.h"

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
	UStaticMeshComponent* EquippedStaticMeshComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BackSlotStaticMeshComponent;
	
/// Public Functions
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void SetupDefaults();

protected:
	// To add mapping context
	virtual void BeginPlay();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	bool CanMove = true;
};

