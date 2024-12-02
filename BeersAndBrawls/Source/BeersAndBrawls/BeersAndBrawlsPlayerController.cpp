#include "BeersAndBrawlsPlayerController.h"
#include "BeersAndBrawlsCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

class UEnhancedInputLocalPlayerSubsystem;

void ABeersAndBrawlsPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	SetupInputComponent();
}

void ABeersAndBrawlsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent)) {
		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Move);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Look);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("Failed to find an Enhanced Input component!"));
	}
}

void ABeersAndBrawlsPlayerController::Move(const FInputActionValue& Value)
{
	if (M_PossesedPawn)
	{
		M_PossesedPawn->Move(Value);
	}
	else if (!M_PossesedPawn)
	{
		M_PossesedPawn = Cast<ABeersAndBrawlsCharacter>(GetPawn());
	}
}

void ABeersAndBrawlsPlayerController::Look(const FInputActionValue& Value)
{
	if (M_PossesedPawn)
	{
		M_PossesedPawn->Look(Value);
	}
	else if (!M_PossesedPawn)
	{
		M_PossesedPawn = Cast<ABeersAndBrawlsCharacter>(GetPawn());
	}
}