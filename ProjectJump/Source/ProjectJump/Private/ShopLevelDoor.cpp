// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "MyPlayerClass.h"
#include "ShopLevelDoor.h"

void AShopLevelDoor::OnInteract()
{
	AMyPlayerClass* player = Cast<AMyPlayerClass>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	APlayerController* controller = Cast<APlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	UE_LOG(LogTemp, Warning, TEXT("Interacting with Shop Level Door"));
	if (controller && player && player->bIsInShop) {
		player->bIsInShop = false;
		player->gameSave();
		UGameplayStatics::OpenLevel(this, "TestLevel3");
		player->loadGame();
	}
	else if (controller && player && !player->bIsInShop) {
		player->bIsInShop = true;
		player->gameSave();
		UGameplayStatics::OpenLevel(this, "Shop");
		player->loadGame();
	}
}

void AShopLevelDoor::InteractReceived()
{
	Super::InteractReceived();
	OnInteract();
}
