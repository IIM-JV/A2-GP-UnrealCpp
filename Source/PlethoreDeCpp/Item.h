// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class PLETHOREDECPP_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
	virtual void Use(class APlethoreDeCppCharacter* Character) PURE_VIRTUAL(AItem::Use, );

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Get Answer"))
	int32 GetAnswerToLifeAndEverythingElse() const { return 42; }

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UStaticMeshComponent> Mesh;
};
