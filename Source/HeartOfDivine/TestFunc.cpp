// Fill out your copyright notice in the Description page of Project Settings.

#include "TestFunc.h"


// Sets default values
ATestFunc::ATestFunc()
{
	PrimaryActorTick.bCanEverTick = false;
}

bool ATestFunc::CallFunction(TArray<FPropertyAndValue> Parameters)
{
    if(!TargetObject)
    {
        UE_LOG(LogTemp, Error, TEXT("TargetObject is null!"));
        return false;
    }

    UFunction* Function = TargetObject->FindFunction(FunctionName);
    if (!Function)
    {
        UE_LOG(LogTemp, Error, TEXT("Function '%s' not found in TargetObject!"), *FunctionName.ToString());
        return false;
    }

    // Проверка доступности функции.  Не вызывайте private функции.
    if (!(Function->FunctionFlags & FUNC_Public))
    {
        UE_LOG(LogTemp, Error, TEXT("Function '%s' is not public!"), *FunctionName.ToString());
        return false;
    }

    // Создаем массив байтов для параметров.
    uint8* ParametersBuffer = new uint8[Function->ParmsSize];
    FMemory::Memzero(ParametersBuffer, Function->ParmsSize);

    // Заполняем параметры из массива FPropertyAndValue.
    for (TFieldIterator<FProperty> PropIt(Function); PropIt && (PropIt->PropertyFlags & CPF_Parm); ++PropIt)
    {
        FProperty* Param = *PropIt;

        // Пропускаем возвращаемое значение.
        if (Param->PropertyFlags & CPF_ReturnParm)
        {
            continue;
        }

        bool bParameterFound = false;
        for (const FPropertyAndValue& ParamValue : Parameters)
        {
            if (Param->GetFName() == ParamValue.PropertyName)
            {
                bParameterFound = true;

                // Преобразуем строку в нужный тип и устанавливаем значение.
                if (FStrProperty* StringProp = CastField<FStrProperty>(Param))
                {
                    StringProp->SetValue_InContainer(ParametersBuffer, ParamValue.StringValue);
                }
                else if (FBoolProperty* BoolProp = CastField<FBoolProperty>(Param))
                {
                    bool BoolValue = (ParamValue.StringValue.ToLower() == "true");
                    BoolProp->SetPropertyValue_InContainer(ParametersBuffer, BoolValue);
                }
                else if (FIntProperty* IntProp = CastField<FIntProperty>(Param))
                {
                    int32 IntValue = FCString::Atoi(*ParamValue.StringValue);
                    IntProp->SetPropertyValue_InContainer(ParametersBuffer, IntValue);
                }
                else if (FFloatProperty* FloatProp = CastField<FFloatProperty>(Param))
                {
                    float FloatValue = FCString::Atof(*ParamValue.StringValue);
                    FloatProp->SetPropertyValue_InContainer(ParametersBuffer, FloatValue);
                }
                // Добавьте поддержку других типов при необходимости.
                else
                {
                    UE_LOG(LogTemp, Warning, TEXT("Unsupported parameter type: %s"), *Param->GetClass()->GetName());
                }
                break;
            }
        }

        if (!bParameterFound)
        {
            UE_LOG(LogTemp, Warning, TEXT("Parameter '%s' not found in Parameters array!"), *Param->GetName());
        }
    }

    // Вызываем функцию.
    TargetObject->ProcessEvent(Function, ParametersBuffer);

    // Очищаем память.
    delete[] ParametersBuffer;

    return true;
}

// Called when the game starts or when spawned
void ATestFunc::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestFunc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FPropertyAndValue::FPropertyAndValue() : PropertyName(NAME_None), StringValue("")
{
}
