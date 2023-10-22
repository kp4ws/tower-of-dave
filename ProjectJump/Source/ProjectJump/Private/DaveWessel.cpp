// Fill out your copyright notice in the Description page of Project Settings.
#include "Kismet/GameplayStatics.h"
#include "MyPlayerClass.h"
#include "DaveWessel.h"

void ADaveWessel::OnInteract()
{

	UE_LOG(LogTemp, Warning, TEXT("Interacting with Dave Wessel"));
	AMyPlayerClass * player = Cast<AMyPlayerClass>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	APlayerController * controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if(controller && player && !bIsInteracting)
	{
		controller->SetViewTargetWithBlend(this, .05f);
		//controller->SetInputMode(FInputModeUIOnly());
		controller->SetShowMouseCursor(true);
		bIsInteracting = true;
		player->SetCanMove(false);
		player->SetInteractWidgetVisibility(false);
	}
	else if (controller && player && bIsInteracting) {
		controller->SetViewTargetWithBlend(player, .05f);
		//controller->SetInputMode(FInputModeGameAndUI());
		controller->SetShowMouseCursor(false);
		bIsInteracting = false;
		player->SetCanMove(true);
	}
}

void ADaveWessel::InteractReceived()
{
	Super::InteractReceived();
	UE_LOG(LogTemp, Warning, TEXT("Interact received on dave wessel"));
	OnInteract();
}
