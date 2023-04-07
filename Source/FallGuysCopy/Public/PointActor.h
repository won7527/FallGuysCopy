// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointActor.generated.h"

UCLASS()
class FALLGUYSCOPY_API APointActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APointActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(Replicated)
		int32 DeadPoints = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool IsSeqStart;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
		bool IsSeqFinish;

};
