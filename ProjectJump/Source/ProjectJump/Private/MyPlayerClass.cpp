// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerClass.h"

void AMyPlayerClass::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("HIYAHIYA"))
}

void AMyPlayerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("TICK"))
}

//void AMyPlayerClass::FlipSprite()
//{
//}

//void AMyPlayerClass::SettingStuffUp()
//{
//}
