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
#include "PlayerAnim.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AFallGuysCharacter::AFallGuysCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("PlayerPreset"));


	springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("springArm"));
	springArm->SetupAttachment(RootComponent);
	springArm->bUsePawnControlRotation = true;
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("cameraComp"));
	cameraComp->SetupAttachment(springArm);
	cameraComp->bUsePawnControlRotation = true;


}

void AFallGuysCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	PlayerAnim = Cast<UPlayerAnim>(GetMesh()->GetAnimInstance());
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

	if (PlayerAnim)
	{
		PlayerAnim->Speed = FVector::DotProduct(GetActorForwardVector(), GetVelocity());
		PlayerAnim->IsFall = GetCharacterMovement()->IsFalling();
	}
	if (PlayerAnim->IsDive)
	{
		CoolTime += DeltaTime;
			if (CoolTime > 0.77f)
			{
				PlayerAnim->IsDive = false;
				CoolTime = 0;
				IsCool = false;
			}
	}
}

// Called to bind functionality to input
void AFallGuysCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	auto InputSystem = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (InputSystem)
	{
		InputSystem->BindAction(IA_ChaMove, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Move);
		InputSystem->BindAction(IA_ChaMove, ETriggerEvent::Completed, this, &AFallGuysCharacter::MoveEnd);
		InputSystem->BindAction(IA_ChaLook, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Look);
		InputSystem->BindAction(IA_ChaJump, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Jumping);
		InputSystem->BindAction(IA_ChaJump, ETriggerEvent::Completed, this, &AFallGuysCharacter::StopJumping);
		InputSystem->BindAction(IA_Dash, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Dash);
		InputSystem->BindAction(IA_Hold, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Holding);
		InputSystem->BindAction(IA_Hold, ETriggerEvent::Completed, this, &AFallGuysCharacter::Release);



	}
}

void AFallGuysCharacter::Move(const FInputActionValue& Values)
{
	FVector2D Axis = Values.Get<FVector2D>();
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (!IsCool)
	{
		AddMovementInput(ForwardDirection, Axis.X);
		AddMovementInput(RightDirection, Axis.Y);
	}
	
}

void AFallGuysCharacter::MoveEnd()
{

}

void AFallGuysCharacter::Look(const FInputActionValue& Values)
{
	FVector2D Axis = Values.Get<FVector2D>();
	AddControllerYawInput(Axis.X);
	AddControllerPitchInput(Axis.Y);

}

void AFallGuysCharacter::Jumping()
{
	if (!IsCool)
	{
		Jump();
		PlayerAnim->IsJump = true;
	}
}

void AFallGuysCharacter::StopJumping()
{

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
		GetCharacterMovement()->MaxWalkSpeed = 100;

	}

}

void AFallGuysCharacter::Dash()
{
	if (!PlayerAnim->IsDive && !PlayerAnim->IsJump && !PlayerAnim->IsFall)
	{
		
		IsCool = true;
		PlayerAnim->IsDive = true;
		LaunchCharacter(GetActorForwardVector() * DashPower + GetActorUpVector() * DashPower, true, true);
		
		
	}
	
}

void AFallGuysCharacter::Release()
{
	GetCharacterMovement()->MaxWalkSpeed = 300;
}
