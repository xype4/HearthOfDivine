// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_ConfigTest.h"

void UDA_ConfigTest::SetMyValue(FVector NewValue)
{
	MyValue = NewValue;
	SaveConfig();
}

FVector UDA_ConfigTest::GetMyValue()
{
	return MyValue;
}
