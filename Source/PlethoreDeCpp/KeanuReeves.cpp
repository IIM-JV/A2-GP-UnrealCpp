// Fill out your copyright notice in the Description page of Project Settings.


#include "KeanuReeves.h"
#include "Logging/StructuredLog.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DamageableInterface.h"

// Sets default values
AKeanuReeves::AKeanuReeves()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("DetectionLight"));
	Light->SetupAttachment(Mesh);

	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AKeanuReeves::BeginPlay()
{
	Super::BeginPlay();

	OriginalColor = Light->GetLightColor();

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AKeanuReeves::OnBeginOverlap);
	Mesh->OnComponentEndOverlap.AddDynamic(this, &AKeanuReeves::OnEndOverlap);
}

void AKeanuReeves::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->Implements<UDamageableInterface>())
	{
		return;
	}

	bool bFirstActor = ActorsInZone.IsEmpty();
	ActorsInZone.Push(OtherActor);
	if (bFirstActor)
	{
		GetWorldTimerManager().SetTimer(DamageTimer, this, &AKeanuReeves::DealDamage, DamageInterval, true);
		Light->SetLightColor(DetectionColor);
	}
}

void AKeanuReeves::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	int32 Idx = ActorsInZone.Find(OtherActor);
	if (Idx == INDEX_NONE)
	{
		// Pas le personnage
		return;
	}

	ActorsInZone.RemoveAt(Idx);

	if (ActorsInZone.IsEmpty())
	{
		GetWorldTimerManager().ClearTimer(DamageTimer);
		Light->SetLightColor(OriginalColor);
	}
}

void AKeanuReeves::DealDamage()
{
	for (AActor* ActorInZone : ActorsInZone)
	{
		if (IDamageableInterface* Damageable = Cast<IDamageableInterface>(ActorInZone))
			Damageable->DealDamage(DamageValue);
	}
}

