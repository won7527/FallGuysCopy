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

}

void AImpactPoint::StartImpact()
{
	
	ImpactFall->SetRadialFalloff(100000, 0, 1, 0, SphereComp->GetScaledSphereRadius(), SphereComp->GetComponentLocation(), Field_FallOff_None);
	ImpactUp->SetRadialVector(10000000000, SphereComp->GetComponentLocation());

	GetFieldSystemComponent()->ApplyPhysicsField(true, Field_ExternalClusterStrain, FallData, ImpactFall);
	GetFieldSystemComponent()->ApplyPhysicsField(true, Field_LinearForce, FallData, ImpactUp);
	
}
	