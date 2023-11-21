// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "MyPlayerClass.h"
#include "Blueprint/UserWidget.h"
#include "JukeBox.h"

void AJukeBox::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with JukeBox"));
	AMyPlayerClass* player = Cast<AMyPlayerClass>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	APlayerController* controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (controller && player && !bIsInteracting)
	{
		controller->SetViewTargetWithBlend(this, .05f);
		//controller->SetInputMode(FInputModeUIOnly());
		controller->SetShowMouseCursor(true);
		bIsInteracting = true;
		player->SetCanMove(false);
		player->SetInteractWidgetVisibility(false);

		if (JukeBoxUI)
		{
			JukeBoxUI->SetVisibility(ESlateVisibility::Visible);
		}
	}
	else if (controller && player && bIsInteracting) {
		controller->SetViewTargetWithBlend(player, .05f);
		controller->SetShowMouseCursor(false);
		bIsInteracting = false;
		player->SetCanMove(true);

		if (JukeBoxUI)
		{
			JukeBoxUI->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}

void AJukeBox::callInteract()
{
	OnInteract();
}

void AJukeBox::InteractReceived()
{
	Super::InteractReceived();
	UE_LOG(LogTemp, Warning, TEXT("Interact received on JukeBox"));
	OnInteract();
}

void AJukeBox::BeginPlay()
{
	Super::BeginPlay();
	playerController = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetController();
	JukeBoxUI = CreateWidget(Cast<APlayerController>(playerController), JukeBoxWidgetClass);

	if (JukeBoxUI)
	{
		JukeBoxUI->AddToViewport(1);
		JukeBoxUI->SetVisibility(ESlateVisibility::Collapsed);
	}
}
