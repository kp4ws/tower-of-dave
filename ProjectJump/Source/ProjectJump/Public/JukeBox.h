// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables.h"
#include "JukeBox.generated.h"

/**
 *
 */
UCLASS()
class PROJECTJUMP_API AJukeBox : public AInteractables
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnInteract();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* JukeBoxUI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> JukeBoxWidgetClass;


	UFUNCTION(BlueprintCallable)
	void callInteract();

	AController* playerController;
	bool bIsInteracting = false;

	virtual void InteractReceived() override;
	virtual void BeginPlay() override;
};
