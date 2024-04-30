// Fill out your copyright notice in the Description page of Project Settings.


#include "AntoineLocalPlayerSubsystem.h"
#include "EnhancedInputSubsystems.h"

void UAntoineLocalPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	UE_LOG(LogTemp, Warning, TEXT("UAntoineLocalPlayerSubsystem::Initialize"));

	Collection.InitializeDependency<UEnhancedInputLocalPlayerSubsystem>();

	// Tu sais que UEnhancedInputLocalPlayerSubsystem est init
}
