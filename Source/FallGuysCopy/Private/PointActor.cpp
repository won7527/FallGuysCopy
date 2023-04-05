// Fill out your copyright notice in the Description page of Project Settings.


#include "PointActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
APointActor::APointActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APointActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APointActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APointActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(APointActor, DeadPoints);

}


