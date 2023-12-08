// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/TextRenderComponent.h"
#include "CoreMinimal.h"
#include "Interactables.h"
#include "Chest.generated.h"

/**
 *
 */
UCLASS()
class PROJECTJUMP_API AChest : public AInteractables
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void OnInteract();

	UFUNCTION(BlueprintCallable)
	void callInteract();

	int value;
	AController* playerController;
	UTextRenderComponent* textBox;
	UAudioComponent* audioComponent;
	bool bIsInteracting = false;
	void OnTimerEnd();
	virtual void InteractReceived() override;
	virtual void BeginPlay() override;

};
