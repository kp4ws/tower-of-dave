// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerClass.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/SpringArmComponent.h"
#include "PaperSpriteComponent.h"
#include "Blueprint/UserWidget.h"
#include "Interactables.h"

void AMyPlayerClass::gameSave_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("Game Saved"));
}

void AMyPlayerClass::loadGame_Implementation()
{
	//UE_LOG(LogTemp, Warning, TEXT("Game loaded!"));
}

void AMyPlayerClass::clearSave_Implementation()
{
}

void AMyPlayerClass::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Game Begun!!!!"));
	this->loadGame();

	InteractWidget = CreateWidget(Cast<APlayerController>(GetController()), InteractWidgetClass);
	JetpackUI = CreateWidget(Cast<APlayerController>(GetController()), JetpackWidgetClass);

	if (InteractWidget)
	{
		InteractWidget->AddToViewport(0);
		SetInteractWidgetVisibility(false);
		UE_LOG(LogTemp, Warning, TEXT("Widget Worked"))
	}

	if (JetpackUI) {
		JetpackUI->AddToViewport(0);
		JetpackUI->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void AMyPlayerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	InteractCheck();
}

void AMyPlayerClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UE_LOG(LogTemp, Warning, TEXT("SetupINput"));
	if (UEnhancedInputComponent* PlayerEnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		if (InteractAction)
		{
			PlayerEnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AMyPlayerClass::Interact);
			UE_LOG(LogTemp, Warning, TEXT("DONEDONEDONE"));
		}
	}
}

void AMyPlayerClass::Interact()
{
	AInteractables* foreign = Cast<AInteractables>(InteractHitResult.GetActor());
	if (Cast<AInteractables>(InteractHitResult.GetActor()) && foreign->ActorHasTag("Interactable"))
	{
		UE_LOG(LogTemp, Warning, TEXT("YES IT WORKD"));
		foreign->InteractReceived();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO IT DIDNT"));
	}
}

void AMyPlayerClass::InteractCheck()
{
	// Get Controller

	if (bCanMove) {
		Cast<APlayerController>(GetController())->GetPlayerViewPoint(ViewVector, ViewRotation);
		FVector VecDirection = this->GetActorLocation();
		FVector InteractEnd = VecDirection;
		InteractEnd.Y += 1000;
		FCollisionQueryParams QueryParams;
		QueryParams.AddIgnoredActor(this);
		GetWorld()->LineTraceSingleByChannel(InteractHitResult, VecDirection, InteractEnd, ECollisionChannel::ECC_GameTraceChannel1, QueryParams);
		if (Cast<APawn>(InteractHitResult.GetActor()) && Cast<APawn>(InteractHitResult.GetActor())->ActorHasTag("Interactable"))
		{
			if (InteractWidget)
			{
				InteractWidget->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else
		{
			if (InteractWidget)
			{
				InteractWidget->SetVisibility(ESlateVisibility::Collapsed);
			}
		}
	}
}

void AMyPlayerClass::SetCanMove(bool input)
{
	bCanMove = input;
}

void AMyPlayerClass::SetInteractWidgetVisibility(bool input)
{
	if (InteractWidget)
	{
		if (input) {
			InteractWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else {
			InteractWidget->SetVisibility(ESlateVisibility::Collapsed);
		}

	}
}
