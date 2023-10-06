// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "MyPlayerClass.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTJUMP_API AMyPlayerClass : public APaperZDCharacter
{
	GENERATED_BODY()
	
public:

//Show here is how to make an implementable event in blueprints
	//UFUNCTION(BlueprintImplementableEvent)
		//void FlipSprite();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
};
