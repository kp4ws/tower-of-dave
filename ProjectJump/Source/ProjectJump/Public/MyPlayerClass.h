// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "InputActionValue.h"
#include "MyPlayerClass.generated.h"
/**
 *
 */
class UInputAction;
class UInputMappingContext;
UCLASS()
class PROJECTJUMP_API AMyPlayerClass : public APaperZDCharacter
{
	GENERATED_BODY()

public:

	//Show here is how to make an implementable event in blueprints
		//UFUNCTION(BlueprintImplementableEvent)
			//void FlipSprite();
	UPROPERTY(EditDefaultsOnly)
	UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsInShop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanMove = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int wallet = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> InteractWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* InteractWidget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* EscapeWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> EscapeWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUserWidget* JetpackUI;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<UUserWidget> JetpackWidgetClass;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SaveGame")
	void clearSave();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SaveGame")
	void gameSave();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SaveGame")
	void loadGame();


	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void Interact();
	void InteractCheck();

	void SetCanMove(bool input);
	void SetInteractWidgetVisibility(bool input);

	FHitResult InteractHitResult;
	FVector ViewVector;
	FRotator ViewRotation;
};
