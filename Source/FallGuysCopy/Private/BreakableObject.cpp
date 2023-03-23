// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableObject.h"
#include "Components/BoxComponent.h"

// Sets default values
ABreakableObject::ABreakableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ABreakableObject::BreakableObjectBeginOverlap);
	//BoxComp->OnComponentEndOverlap.AddDynamic(this, &ABreakableObject::BreakableObjectEndOverlap);

}

// Called when the game starts or when spawned
void ABreakableObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakableObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsOnObject)
	{
		Timer += DeltaTime;
		if (Timer >= TimeLimit)
		{
			IsBeginOverlap = false;
			IsOnObject = false;
			Timer = 0;
		}
	}

	if (IsBroken)
	{
		if (ShakeCount == 1)
		{
			SetActorLocation(GetActorLocation() + ShakeDirec * 5);
			ShakeCount++;
		}
		else if (ShakeCount % 5 == 0)
		{
			SetActorLocation(GetActorLocation() - ShakeDirec * 10);
			ShakeCount++;
		}
		else if (ShakeCount % 5 == 3)
		{
			SetActorLocation(GetActorLocation() + ShakeDirec * 10);
			ShakeCount++;
		}
		ShakeCount++;
	}

}

void ABreakableObject::BreakableObjectBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!IsBeginOverlap && HitCount != HitCountLimit)
	{
		IsBeginOverlap = true;
		IsOnObject = true;
		HitCount++;
		UE_LOG(LogTemp, Warning, TEXT("%d"), HitCount);
	}
	else if (!IsBeginOverlap && HitCount == HitCountLimit)
	{
		// 2檬 第 何辑瘤绰 贸府
		ShakeDirec =  OtherActor->GetActorRightVector();
		HitCount = 0;
		IsBroken = true;
	}

}

//void ABreakableObject::BreakableObjectEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//	if (!IsEndOverlap)
//	{
//		IsEndOverlap = true;
//		IsBeginOverlap = false;
//		IsOnObject = false;
//		Timer = 0;
//
//		UE_LOG(LogTemp, Warning, TEXT("HIT OUT"));
//
//	}
//	
//
//}
