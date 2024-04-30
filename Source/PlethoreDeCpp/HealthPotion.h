// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class PLETHOREDECPP_API AHealthPotion : public AItem
{
	GENERATED_BODY()
	
	public:
		void Use(class APlethoreDeCppCharacter* Character) override;

		UPROPERTY(EditAnywhere, meta = (ClampMax = 100, ClampMin = 1))
		int32 HealValue = 10;
};
