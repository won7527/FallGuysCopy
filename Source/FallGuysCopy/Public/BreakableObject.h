// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BreakableObject.generated.h"

UCLASS()
class FALLGUYSCOPY_API ABreakableObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	UPROPERTY()
	bool IsOnObject;
	UPROPERTY()
	bool IsBeginOverlap;
	UPROPERTY()
	bool IsEndOverlap;

	UPROPERTY()
		float Timer;

	UPROPERTY()
		float TimeLimit = 2.0f;
	UPROPERTY()
		int32 HitCount;
	UPROPERTY()
		int32 HitCountLimit = 2;

	UPROPERTY()
		FVector ShakeDirec;

	UPROPERTY()
		bool IsBroken;
	UPROPERTY()
		int32 ShakeCount = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* BoxComp;

	UFUNCTION()
		void BreakableObjectBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//UFUNCTION()
		//void BreakableObjectEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);


};
