// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "FallGuysCharacter.generated.h"

UCLASS()
class FALLGUYSCOPY_API AFallGuysCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFallGuysCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* PlayerCam;

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputMappingContext* IMC_Player;

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Move;
	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_LookUp;
	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Jump;
	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Grab;
	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Dash;


	void Move(const FInputActionValue& Value);
	void LookUp(const FInputActionValue& Value);
	void Jumping(const FInputActionValue& Value);
	void Grab(const FInputActionValue& Value);
	void Dash(const FInputActionValue& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DashSpeed = 1000;

};
