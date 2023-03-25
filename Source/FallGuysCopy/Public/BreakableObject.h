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
		float TimeLimit = 3.0f;
	UPROPERTY()
		int32 HitCount;
	UPROPERTY()
		int32 HitCountLimit = 2;

	UPROPERTY()
		bool IsLast;
	UPROPERTY()
		int32 BrokenCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* InvisibleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* VisibleMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UGeometryCollectionComponent* BreakableMeshComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UChildActorComponent* ImpactActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class AImpactPoint> ImpactPointActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UMaterialInterface* InvisibleMat;
	

	UFUNCTION()
		void BreakableObjectBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void BreakableObjectEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
