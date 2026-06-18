// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DA_ConfigTest.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SV_ConfigTestActor.generated.h"

UCLASS(Blueprintable, Config = GameEditor)
class HEARTOFDIVINE_API ASV_ConfigTestActor : public AActor
{
	GENERATED_BODY()

public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UDA_ConfigTest* PositionData;

	ASV_ConfigTestActor();

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override
	{
		if (PositionData)
		{
			SetActorLocation(PositionData->GetMyValue());
		}
	}


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
