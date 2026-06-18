// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_ConfigTest.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, Config = GameEditor)

class HEARTOFDIVINE_API UDA_ConfigTest : public UDataAsset
{
	GENERATED_BODY()

    private:

    UPROPERTY(Config, VisibleAnywhere)
    FVector MyValue;

    public:

    UFUNCTION(BlueprintCallable)
    void SetMyValue(FVector NewValue);

    UFUNCTION(BlueprintCallable)
    FVector GetMyValue();
};
