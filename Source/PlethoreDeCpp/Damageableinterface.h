#pragma once

#include "CoreMinimal.h"
#include "DamageableInterface.generated.h"

UINTERFACE()
class UDamageableInterface : public UInterface
{
	GENERATED_BODY()
};

class IDamageableInterface
{
	GENERATED_BODY()

	public:
		virtual void DealDamage(int32 value) = 0;
};