// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpactPoint.h"
#include "Components/SphereComponent.h"
#include "Field/FieldSystemComponent.h"


AImpactPoint::AImpactPoint()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetSphereRadius(SphereCompRadius);
	SphereComp->SetupAttachment(RootComponent);

	ImpactFall = CreateDefaultSubobject<URadialFalloff>(TEXT("ImpactFall"));
	ImpactUp = CreateDefaultSubobject<URadialVector>(TEXT("ImpactUp"));
	ImpactMake = CreateDefaultSubobject<UFieldSystemComponent>(TEXT("ImpactMake"));

}

void AImpactPoint::StartImpact()
{
	ImpactFall->SetRadialFalloff(10000, 0, 1, 0, SphereCompRadius, SphereComp->GetComponentLocation(), Field_FallOff_None);
	ImpactUp->SetRadialVector(1000000, SphereComp->GetComponentLocation());
	ImpactMake->ApplyPhysicsField(true, Field_ExternalClusterStrain, FallData, ImpactFall);
	ImpactMake->ApplyPhysicsField(true, Field_ExternalClusterStrain, UpData, ImpactFall);
	
}
	