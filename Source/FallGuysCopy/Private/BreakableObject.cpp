// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakableObject.h"
#include "Components/BoxComponent.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "ImpactPoint.h"

// Sets default values
ABreakableObject::ABreakableObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	SetRootComponent(BoxComp);
	BoxComp->SetRelativeScale3D(FVector(1.0, 1.0, 0.33));
	OnActorBeginOverlap.AddDynamic(this, &ABreakableObject::BreakableObjectBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ABreakableObject::BreakableObjectEndOverlap);

	InvisibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InvisibleMesh"));
	InvisibleMesh->SetupAttachment(RootComponent);
	InvisibleMesh->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	VisibleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisibleMesh"));
	VisibleMesh->SetupAttachment(RootComponent);
	VisibleMesh->SetRelativeScale3D(FVector(0.6));
	VisibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BreakableMeshComp = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("BreakableMeshComp"));
	BreakableMeshComp->SetupAttachment(RootComponent);
	BreakableMeshComp->SetRelativeScale3D(FVector(0.6, 0.6, 1.8));
	BreakableMeshComp->SetVisibility(false);
	ImpactActor = CreateDefaultSubobject<UChildActorComponent>(TEXT("ImpactActor"));
	ImpactActor->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (Cube.Succeeded())
	{
		InvisibleMesh->SetStaticMesh(Cube.Object);
		VisibleMesh->SetStaticMesh(Cube.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> InvisibleMatAsset(TEXT("/Script/Engine.Material'/Game/TW/Material/MAT_Invisible.MAT_Invisible'"));
	if (InvisibleMatAsset.Succeeded())
	{
		InvisibleMat = InvisibleMatAsset.Object;
		InvisibleMesh->SetMaterial(0, InvisibleMat);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> RedMatAsset(TEXT("/Script/Engine.Material'/Game/TW/Material/MAT_R.MAT_R'"));
	if (RedMatAsset.Succeeded())
	{
		VisibleMesh->SetMaterial(0, RedMatAsset.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> GreenMatAsset(TEXT("/Script/Engine.Material'/Game/TW/Material/MAT_G.MAT_G'"));
	if (GreenMatAsset.Succeeded())
	{
		VisibleMesh->SetMaterial(1, GreenMatAsset.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial> BlueMatAsset(TEXT("/Script/Engine.Material'/Game/TW/Material/MAT_B.MAT_B'"));
	if (BlueMatAsset.Succeeded())
	{
		VisibleMesh->SetMaterial(2, BlueMatAsset.Object);
	}
	ConstructorHelpers::FObjectFinder<UGeometryCollection> BreakableMeshCompAsset(TEXT("/Script/GeometryCollectionEngine.GeometryCollection'/Game/TW/Material/BreakableMesh.BreakableMesh'"));
	if (BreakableMeshCompAsset.Succeeded())
	{
		BreakableMeshComp->SetRestCollection(BreakableMeshCompAsset.Object);
		BreakableMeshComp->SetSimulatePhysics(false);
	}
	ConstructorHelpers::FClassFinder<AActor> ImpactPointAsset(TEXT("/Script/Engine.Blueprint'/Game/TW/Blueprint/BP_ImpactPoint.BP_ImpactPoint_C'"));
	if (ImpactPointAsset.Succeeded())
	{
		ImpactPointActor = ImpactPointAsset.Class;
		ImpactActor->SetChildActorClass(ImpactPointActor);
	}



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

	if (IsOnObject && !IsLast)
	{
		if (HitCount == HitCountLimit)
		{
			IsLast = true;
		}
		if (Timer == 0 && HitCount < HitCountLimit)
		{
			HitCount++;
			VisibleMesh->SetMaterial(0, VisibleMesh->GetMaterial(HitCount));
		}
		Timer += DeltaTime;
		if (Timer >= TimeLimit)
		{

			Timer = 0;
		}
		if (Timer * 13 <= 1)
		{
			VisibleMesh->SetRelativeScale3D(FMath::Lerp<FVector, float>(FVector(0.6f), FVector(0.65f),  Timer * 13));
		}
		else if (Timer * 13 <= 2)
		{
			VisibleMesh->SetRelativeScale3D(FMath::Lerp<FVector, float>(FVector(0.65f), FVector(0.6f), Timer * 13 - 1));
		}
	}
	
	if (IsLast && BrokenCount < 5)
	{
	Timer += DeltaTime;
		if (Timer * 7 <= 1)
		{
			VisibleMesh->SetRelativeScale3D(FMath::Lerp<FVector, float>(FVector(0.6f), FVector(0.65f), Timer * 7));
		}
		else if (Timer * 7 <= 2)
		{
			VisibleMesh->SetRelativeScale3D(FMath::Lerp<FVector, float>(FVector(0.65f), FVector(0.6f), Timer * 7 - 1));
		}
		else
		{
			BrokenCount++;
			Timer = 0;
		}

	}
	else if (IsLast && BrokenCount == 5)
	{
		VisibleMesh->SetVisibility(false);
		InvisibleMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		BreakableMeshComp->SetSimulatePhysics(true);
		BreakableMeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Cast<AImpactPoint>(ImpactActor->GetChildActor())->StartImpact();
		BrokenCount++;
		
	}
	else if (IsLast && BrokenCount > 5)
	{
		Timer += DeltaTime;
		if (Timer > 3.0f)
		{
			Destroy();
		}
	}


}

void ABreakableObject::BreakableObjectBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("asdas"));
	IsOnObject = true;
	
}

void ABreakableObject::BreakableObjectEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("IsOut"));
	IsOnObject = false;
	Timer = 0;
}
