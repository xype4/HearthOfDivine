// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DA_Palette.generated.h"

UENUM(BlueprintType)
enum class EColorNameEnum : uint8
{
    Background     UMETA(DisplayName = "Background"),
    ButtonBackground   UMETA(DisplayName = "ButtonBackground"),
    ButtonHoverBackground    UMETA(DisplayName = "ButtonHoverBackground"),
    ButtonSelectedBackground  UMETA(DisplayName = "ButtonSelectedBackground"),
    ButtonText   UMETA(DisplayName = "ButtonText"),
    ButtonHoverText    UMETA(DisplayName = "ButtonHoverText"),
    ButtonSelectedText  UMETA(DisplayName = "ButtonSelectedText")
};


UCLASS(BlueprintType)
class HEARTOFDIVINE_API UDA_Palette : public UDataAsset
{
    GENERATED_BODY()

public:

    UDA_Palette();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Palette")
    TMap<EColorNameEnum, FLinearColor> Colors;

    UFUNCTION(BlueprintPure, Category = "Palette")
    FLinearColor GetColor(EColorNameEnum Name);
};
