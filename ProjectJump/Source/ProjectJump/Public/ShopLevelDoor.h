// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactables.h"
#include "ShopLevelDoor.generated.h"

/**
 *
 */
UCLASS()
class PROJECTJUMP_API AShopLevelDoor : public AInteractables
{
	GENERATED_BODY()
public:
	UFUNCTION()
	void OnInteract();

	bool bIsInteracting = false;
	virtual void InteractReceived() override;
};
