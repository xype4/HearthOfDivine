// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_ConfigTest.h"

void UDA_ConfigTest::SetMyValue(float NewValue)
{
	MyValue = NewValue;
	SaveConfig();
}

float UDA_ConfigTest::GetMyValue()
{
	return MyValue;
}
