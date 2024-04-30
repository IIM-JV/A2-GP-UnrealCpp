// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KeanuReeves.generated.h"

class UPointLightComponent;
class UStaticMeshComponent;

UCLASS()
class PLETHOREDECPP_API AKeanuReeves : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeanuReeves();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

public:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPointLightComponent> Light;

	UPROPERTY(EditAnywhere)
	FLinearColor DetectionColor = FLinearColor(1.0f, 0.0f, 0.0f);

private:
	void DealDamage();

	UPROPERTY()
	TArray<TObjectPtr<AActor>> ActorsInZone;

	UPROPERTY(EditAnywhere)
	int32 DamageValue = 10;

	UPROPERTY(EditAnywhere)
	float DamageInterval = 0.1f;

	FTimerHandle DamageTimer;
	FLinearColor OriginalColor;
};
