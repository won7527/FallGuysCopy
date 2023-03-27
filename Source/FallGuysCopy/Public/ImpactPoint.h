// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Field/FieldSystemActor.h"
#include "ImpactPoint.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API AImpactPoint : public AFieldSystemActor
{
	GENERATED_BODY()

public:
		AImpactPoint();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USphereComponent* SphereComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class URadialFalloff* ImpactFall;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class URadialVector* ImpactUp;

	class UFieldSystemMetaData* FallData;
	class UFieldSystemMetaData* UpData;

	UPROPERTY()
		float SphereCompRadius = 80;

	UFUNCTION(BlueprintCallable)
		void StartImpact();

};
