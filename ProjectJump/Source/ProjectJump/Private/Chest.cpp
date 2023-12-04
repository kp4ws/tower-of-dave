// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "MyPlayerClass.h"
#include "Blueprint/UserWidget.h"
#include "Components/AudioComponent.h"
#include "Chest.h"

void AChest::callInteract()
{
	OnInteract();
}

void AChest::InteractReceived()
{
	Super::InteractReceived();
	UE_LOG(LogTemp, Warning, TEXT("Interact received on Chest"));
	OnInteract();
}

void AChest::BeginPlay()
{
	Super::BeginPlay();
	playerController = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetController();
	value = FMath::RandRange(30, 100);
	textBox = FindComponentByClass<UTextRenderComponent>();
	textBox->SetText(FText::FromString(FString::FromInt(value)));
	textBox->SetVisibility(false);
	audioComponent = FindComponentByClass<UAudioComponent>();
}

void AChest::OnInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacting with Chest"));
	AMyPlayerClass* player = Cast<AMyPlayerClass>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	APlayerController* controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (controller && player && textBox && audioComponent)
	{
		player->wallet += value;
		textBox->SetVisibility(true);
		audioComponent->SetVolumeMultiplier(2.0f);
		audioComponent->Play();
	}

	//wait for 2 seconeds
	FTimerHandle timer;
	GetWorldTimerManager().SetTimer(timer, this, &AChest::OnTimerEnd, 3.5f, false);

}

void AChest::OnTimerEnd()
{
	this->Destroy();
}
