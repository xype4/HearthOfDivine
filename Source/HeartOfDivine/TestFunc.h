// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h" 
#include "UObject/UObjectIterator.h"
#include "GameFramework/Actor.h"
#include "TestFunc.generated.h"


USTRUCT(BlueprintType)
struct FPropertyAndValue
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	FName PropertyName;  // Имя параметра функции.

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameter")
	FString StringValue; // Значение параметра (храним как строку, потом преобразуем).

	FPropertyAndValue();
};


UCLASS()
class HEARTOFDIVINE_API ATestFunc : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestFunc();

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Function Caller")
	AActor* TargetObject;

	// UPROPERTY для указания имени функции.  Пользователь вводит имя в редакторе.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Function Caller")
	FName FunctionName;

	// Функция для вызова функции на TargetObject
	UFUNCTION(BlueprintCallable, Category = "Function Caller")
	bool CallFunction(TArray<FPropertyAndValue> Parameters);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
