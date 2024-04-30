// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "AntoineLocalPlayerSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class PLETHOREDECPP_API UAntoineLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()
	
	public:
		void Initialize(FSubsystemCollectionBase& Collection) override;
};
