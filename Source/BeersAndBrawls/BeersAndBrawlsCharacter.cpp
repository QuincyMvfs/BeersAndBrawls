// Copyright Epic Games, Inc. All Rights Reserved.

#include "BeersAndBrawlsCharacter.h"

#include "BeersAndBrawlsPlayerController.h"
#include "Engine/LocalPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/Controller.h"
#include "InputActionValue.h"
#include "Actors/ActorComponents/CombatComponent.h"
#include "Actors/ActorComponents/CurrencyComponent.h"
#include "Actors/ActorComponents/CustomizationComponent.h"
#include "Actors/ActorComponents/HealthComponent.h"
#include "Actors/ActorComponents/InventoryComponent.h"
#include "Actors/ActorComponents/LevelingComponent.h"
#include "Actors/ActorComponents/StatusEffectComponent.h"
#include "Enums/EPlayerInputState.h"
#include "Interface/Interactable.h"
#include "Items/Consumable.h"
#include "Items/Weapon.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

// ABeersAndBrawlsCharacter constructor
ABeersAndBrawlsCharacter::ABeersAndBrawlsCharacter()
{
	SetupDefaults();
	
/// Custom Subobjects
	CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	CurrencyComponent = CreateDefaultSubobject<UCurrencyComponent>(TEXT("CurrencyComponent"));
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	LevelingComponent = CreateDefaultSubobject<ULevelingComponent>(TEXT("LevelingComponent"));
	CustomizationComponent = CreateDefaultSubobject<UCustomizationComponent>(TEXT("CustomizationComponent"));
	
	StatusEffectComponent = CreateDefaultSubobject<UStatusEffectComponent>(TEXT("StatusEffectComponent"));
	WeaponEquippedStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMeshSlot"));
	WeaponEquippedStaticMeshComponent->SetupAttachment(GetMesh(), "WeaponSocket");

	WeaponBackSlotStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HolsteredMeshSlot"));
	WeaponBackSlotStaticMeshComponent->SetupAttachment(GetMesh(), "HolsterSocket");
	
	ConsumableSlotStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ConsumableSocket"));
	ConsumableSlotStaticMeshComponent->SetupAttachment(GetMesh(), "ConsumableSocket");
	
	
	CombatCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CombatCamera"));
	CombatCamera->SetupAttachment(GetCapsuleComponent());
}

void ABeersAndBrawlsCharacter::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

void ABeersAndBrawlsCharacter::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D MovementVector = Value.Get<FVector2D>();

	if (Controller != nullptr && CanMove)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	
		// get right vector 
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

		// add movement 
		AddMovementInput(ForwardDirection, MovementVector.Y);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void ABeersAndBrawlsCharacter::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr && CanMove)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void ABeersAndBrawlsCharacter::SetupDefaults()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
		
	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.0f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
}

void ABeersAndBrawlsCharacter::TryInteract()
{
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	TArray<FHitResult> HitResults;
	FVector PlayerPos = this->GetActorLocation();

	bool IsHit = GetWorld()->SweepMultiByChannel( HitResults, PlayerPos, PlayerPos, FQuat::Identity,
		ECC_Visibility, FCollisionShape::MakeSphere(150.0f), QueryParams);

	if (IsHit)
	{
		for (auto HitResult : HitResults)
		{
			if (HitResult.GetActor()->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_Interact(HitResult.GetActor(),
					Cast<ABeersAndBrawlsPlayerController>(GetController()), this);

				break;
			}
		}
	}
}

void ABeersAndBrawlsCharacter::DisplayNewWeaponMesh(EPlayerInputState NewState)
{
	//EquippedStaticMeshComponent
	//BackSlotStaticMeshComponent

	switch (NewState)
	{
		case EPlayerInputState::Combat:
			if (InventoryComponent->M_SelectedWeapon) WeaponEquippedStaticMeshComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
			else { WeaponEquippedStaticMeshComponent->SetStaticMesh(InventoryComponent->M_DefaultSelectedWeapon->ItemMesh); }
			WeaponBackSlotStaticMeshComponent->SetStaticMesh(nullptr);
			return;
		case EPlayerInputState::World:
			WeaponEquippedStaticMeshComponent->SetStaticMesh(nullptr);
		if (InventoryComponent->M_SelectedWeapon) WeaponBackSlotStaticMeshComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
		else { WeaponBackSlotStaticMeshComponent->SetStaticMesh(InventoryComponent->M_DefaultSelectedWeapon->ItemMesh); }
			return;
		case EPlayerInputState::Shopping:
			WeaponEquippedStaticMeshComponent->SetStaticMesh(nullptr);
		if (InventoryComponent->M_SelectedWeapon) WeaponBackSlotStaticMeshComponent->SetStaticMesh(InventoryComponent->M_SelectedWeapon->ItemMesh);
		else { WeaponBackSlotStaticMeshComponent->SetStaticMesh(InventoryComponent->M_DefaultSelectedWeapon->ItemMesh); }
			return;
		
	}
}

void ABeersAndBrawlsCharacter::DisplayNewConsumableMesh()
{
	if (InventoryComponent->M_SelectedConsumable)
	{
		ConsumableSlotStaticMeshComponent->SetStaticMesh(InventoryComponent->M_SelectedConsumable->ItemMesh);
	}
}

void ABeersAndBrawlsCharacter::SwapCameras(int Index)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0))
	{
		if (Index == 0)
		{
			PlayerController->SetViewTargetWithBlend(this, 0.5f);
			FollowCamera->SetActive(true);
			CombatCamera->SetActive(false);
		}
		else if (Index == 1)
		{
			PlayerController->SetViewTargetWithBlend(this, 0.5f);
			FollowCamera->SetActive(false);
			CombatCamera->SetActive(true);
		}
	}
}

void ABeersAndBrawlsCharacter::SetCanSelectAbility(bool Value)
{
	// This is used on the WBP_CombatHUD
	CanSelectAbility = Value;
	OnTurnChangedEvent.Broadcast();
}
