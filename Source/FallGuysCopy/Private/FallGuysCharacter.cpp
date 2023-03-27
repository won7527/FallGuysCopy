// Fill out your copyright notice in the Description page of Project Settings.


#include "FallGuysCharacter.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AFallGuysCharacter::AFallGuysCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCam = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCam"));
	PlayerCam->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AFallGuysCharacter::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerController = Cast<APlayerController>(GetWorld()->GetFirstPlayerController());

	if (PlayerController)
	{
		auto LocalPlayerCharacter = PlayerController->GetLocalPlayer();
		auto SubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayerCharacter);
		if (SubSystem)
		{
			SubSystem->AddMappingContext(IMC_Player, 0);
		}
	}
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

	auto InputSystem = CastChecked<UEnhancedInputComponent>(PlayerInputComponent);
	if (InputSystem)
	{
		InputSystem->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Move);
		InputSystem->BindAction(IA_LookUp, ETriggerEvent::Triggered, this, &AFallGuysCharacter::LookUp);
		InputSystem->BindAction(IA_Jump, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Jumping);
		InputSystem->BindAction(IA_Grab, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Grab);
		InputSystem->BindAction(IA_Dash, ETriggerEvent::Triggered, this, &AFallGuysCharacter::Dash);
	}
}

void AFallGuysCharacter::Move(const FInputActionValue& Value)
{
	FVector2D CharacterMove = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), CharacterMove.X);
	AddMovementInput(GetActorRightVector(), CharacterMove.Y);
	UE_LOG(LogTemp, Warning, TEXT("IsOn"));


}
void AFallGuysCharacter::LookUp(const FInputActionValue& Value)
{
	FVector2D CharacterLookUp = Value.Get<FVector2D>();
	AddControllerYawInput(CharacterLookUp.X);
	AddControllerPitchInput(CharacterLookUp.Y);
}
void AFallGuysCharacter::Jumping(const FInputActionValue& Value)
{
	Jump();
}
void AFallGuysCharacter::Grab(const FInputActionValue& Value)
{

}
void AFallGuysCharacter::Dash(const FInputActionValue& Value)
{
	LaunchCharacter(GetActorForwardVector() * DashSpeed, true, true);
}

