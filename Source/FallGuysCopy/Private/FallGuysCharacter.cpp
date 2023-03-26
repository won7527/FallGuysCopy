// Fill out your copyright notice in the Description page of Project Settings.


#include "FallGuysCharacter.h"
#include <EnhancedInputSubsystems.h>
#include <Engine/LocalPlayer.h>
#include <FallGuysGameModeBase.h>
#include <EnhancedInputComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/Character.h>
#include <Components/CapsuleComponent.h>


// Sets default values
AFallGuysCharacter::AFallGuysCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("PlayerPreset"));


	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->bUsePawnControlRotation = true;
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("cameraComp"));
	cameraComp->SetupAttachment(springArm);
	cameraComp->bUsePawnControlRotation = true;


}

// Called when the game starts or when spawned
void AFallGuysCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	auto PC = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());

	if (PC)
	{
		auto localPlayer = PC->GetLocalPlayer();
		auto subSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(localPlayer);
		if (subSystem)
		{
			subSystem->AddMappingContext(IMC_ChaInput,0);
		}
	}

	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AFallGuysCharacter::OnOverlap);


}

// Called every frame
void AFallGuysCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFallGuysCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto InputSystem = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (InputSystem)
	{
		InputSystem->BindAction(IA_ChaMove, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Move);
		InputSystem->BindAction(IA_ChaLook, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Look);
		InputSystem->BindAction(IA_ChaJump, ETriggerEvent::Triggered, this, &ACharacter::Jump);
		InputSystem->BindAction(IA_ChaJump, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AFallGuysCharacter::Jumping);
		PlayerInputComponent->BindAction(TEXT("Hold"), IE_Pressed, this, &AFallGuysCharacter::Holding);

	}
}

void AFallGuysCharacter::Move(const FInputActionValue& Values)
{
	FVector2D Axis = Values.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), Axis.X);
	AddMovementInput(GetActorRightVector(), Axis.Y);
}

void AFallGuysCharacter::Look(const FInputActionValue& Values)
{

	FVector2D Axis = Values.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(Axis.Y);

}

void AFallGuysCharacter::Jumping()
{
	Jump();
}

void AFallGuysCharacter::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	isOverlap = true;

}

void AFallGuysCharacter::Holding()
{
	
	UE_LOG(LogTemp, Warning, TEXT("Hold"));
	if (isOverlap == true)
	{
		UE_LOG(LogTemp, Warning, TEXT("OverLapHold"));

	}
	else
	{
		return;
	}
	
}

