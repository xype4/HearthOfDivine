// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_Palette.h"

UDA_Palette::UDA_Palette()
{
    UEnum* Enum = StaticEnum<EColorNameEnum>();
    if(Enum)
    {
        for(int i = 0; i< Enum->NumEnums()-1;i++)
        {
            EColorNameEnum Key = static_cast<EColorNameEnum>(Enum->GetValueByIndex(i));
            Colors.Add(Key, FLinearColor::White);
        }
    }
}

FLinearColor UDA_Palette::GetColor(EColorNameEnum Name)
{
    return *Colors.Find(Name);
}
