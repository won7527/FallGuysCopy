// Fill out your copyright notice in the Description page of Project Settings.


#include "StartPos.h"
#include "PointActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AStartPos::AStartPos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStartPos::BeginPlay()
{
	Super::BeginPlay();
	PointActor = Cast<APointActor>(UGameplayStatics::GetActorOfClass(GetWorld(), APointActor::StaticClass()));

}

// Called every frame
void AStartPos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PointActor->IsSeqFinish)
	{
		if (!IsHide)
		{
			IsHide = true;
			SetActorHiddenInGame(true);
			SetActorEnableCollision(false);
		}
	}

}

