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
		Subsystem->AddMappingContext(CombatMappingContext, 1);
	}

	SetupInputComponent();
}

void ABeersAndBrawlsPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Looking and Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABeersAndBrawlsPlayerController::Look);

		
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
	if (M_PossesedPawn)
	{
		M_PossesedPawn->Move(Value);
	}
}

void ABeersAndBrawlsPlayerController::Look(const FInputActionValue& Value)
{
	if (M_PossesedPawn)
	{
		M_PossesedPawn->Look(Value);
	}
}