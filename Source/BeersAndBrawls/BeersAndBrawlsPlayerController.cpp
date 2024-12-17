#include "BeersAndBrawlsPlayerController.h"
#include "BeersAndBrawlsCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Actors/ActorComponents/CombatComponent.h"
#include "Enums/ECombatKey.h"
#include "Enums/EPlayerInputState.h"

class UEnhancedInputLocalPlayerSubsystem;

void ABeersAndBrawlsPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
		Subsystem->AddMappingContext(CombatMappingContext, 1);
	}

	UpdatePlayerInputState(EPlayerInputState::World);
}

void ABeersAndBrawlsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Looking and Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Look);
		// Interacting
		EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::SendInteractAction);

		// Combat Inputs
		EnhancedInputComponent->BindAction(CombatUpAction, ETriggerEvent::Started, this, &ABeersAndBrawlsPlayerController::SendUpInput);
		EnhancedInputComponent->BindAction(CombatDownAction, ETriggerEvent::Started, this, &ABeersAndBrawlsPlayerController::SendDownInput);
		EnhancedInputComponent->BindAction(CombatLeftAction, ETriggerEvent::Started, this, &ABeersAndBrawlsPlayerController::SendLeftInput);
		EnhancedInputComponent->BindAction(CombatRightAction, ETriggerEvent::Started, this, &ABeersAndBrawlsPlayerController::SendRightInput);
		
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("Failed to find an Enhanced Input component!"));
	}
}

void ABeersAndBrawlsPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	M_PossesedPawn = Cast<ABeersAndBrawlsCharacter>(InPawn);
}

void ABeersAndBrawlsPlayerController::Move(const FInputActionValue& Value)
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::World)
	{
		M_PossesedPawn->Move(Value);
	}
}

void ABeersAndBrawlsPlayerController::Look(const FInputActionValue& Value)
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::World)
	{
		M_PossesedPawn->Look(Value);
	}
}


// CombatInputs
void ABeersAndBrawlsPlayerController::SendUpInput()
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::Combat)
	{
		M_PossesedPawn->CombatComponent->ReceiveInput(ECombatKey::Up);
	}
}

void ABeersAndBrawlsPlayerController::SendDownInput()
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::Combat)
	{
		M_PossesedPawn->CombatComponent->ReceiveInput(ECombatKey::Down);
	}
}

void ABeersAndBrawlsPlayerController::SendLeftInput()
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::Combat)
	{
		M_PossesedPawn->CombatComponent->ReceiveInput(ECombatKey::Left);
	}
}

void ABeersAndBrawlsPlayerController::SendRightInput()
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::Combat)
	{
		M_PossesedPawn->CombatComponent->ReceiveInput(ECombatKey::Right);
	}
}

void ABeersAndBrawlsPlayerController::SendInteractAction()
{
	if (M_PossesedPawn && M_CurrentInputState == EPlayerInputState::World)
	{
		M_PossesedPawn->TryInteract();
	}
}

void ABeersAndBrawlsPlayerController::UpdatePlayerInputState(EPlayerInputState NewState)
{
	if (M_PossesedPawn)
	{
		M_CurrentInputState = NewState;
		M_PossesedPawn->DisplayNewWeaponMesh(NewState);
	}
}

