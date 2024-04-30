// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthPotion.h"
#include "PlethoreDeCppCharacter.h"

void AHealthPotion::Use(APlethoreDeCppCharacter* Character)
{
	Character->Heal(HealValue);

	Destroy();
}
