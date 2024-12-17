// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "BeersAndBrawls/BeersAndBrawlsCharacter.h"

void IInteractable::Interact_Implementation(ABeersAndBrawlsPlayerController* PlayerController, ABeersAndBrawlsCharacter* PlayerActor)
{
	Execute_Interact(PlayerActor->_getUObject(), PlayerController, PlayerActor);
}
