// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables.h"
#include "DaveWessel.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJUMP_API ADaveWessel : public AInteractables
{
	GENERATED_BODY()
	
	UFUNCTION()
	void OnInteract();
	bool bIsInteracting = false;
	virtual void InteractReceived() override;
};
