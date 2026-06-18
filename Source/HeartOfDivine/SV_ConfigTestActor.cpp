// Fill out your copyright notice in the Description page of Project Settings.


#include "SV_ConfigTestActor.h"

// Sets default values
ASV_ConfigTestActor::ASV_ConfigTestActor()
{
	PrimaryActorTick.bCanEverTick = true;

	if (PositionData)
	{
		PositionData->SetMyValue(GetActorLocation());
	}
}

// Called when the game starts or when spawned
void ASV_ConfigTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASV_ConfigTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

