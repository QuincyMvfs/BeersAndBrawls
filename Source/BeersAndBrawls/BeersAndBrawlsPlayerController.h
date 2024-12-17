// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enums/EPlayerInputState.h"
#include "GameFramework/PlayerController.h"
#include "BeersAndBrawlsPlayerController.generated.h"

enum class EPlayerInputState : uint8;
struct FInputActionValue;
class UInputAction;
class ABeersAndBrawlsCharacter;
class UInputMappingContext;
/**
 * 
 */
UCLASS()
class BEERSANDBRAWLS_API ABeersAndBrawlsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	// Combat Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* CombatMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CombatUpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CombatDownAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CombatLeftAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* CombatRightAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EPlayerInputState M_CurrentInputState = EPlayerInputState::World;

public:
	// APawn interface
	UFUNCTION(BlueprintCallable)
	virtual void SetupInputComponent() override;

	virtual void OnPossess(APawn* InPawn) override;
	
	// To add mapping context
	virtual void BeginPlay() override;

	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	void SendUpInput();
	void SendDownInput();
	void SendLeftInput();
	void SendRightInput();

	ABeersAndBrawlsCharacter* M_PossesedPawn;
			
};
