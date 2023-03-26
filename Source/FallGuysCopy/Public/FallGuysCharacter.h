// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <InputActionValue.h>
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

	UPROPERTY(EditAnywhere,Category = "Input")
	class UInputMappingContext* IMC_ChaInput;

	UPROPERTY(EditAnywhere,Category = "Input")
	class UInputAction* IA_ChaMove;
	UPROPERTY(EditAnywhere,Category = "Input")
	class UInputAction* IA_ChaLook;
	UPROPERTY(EditAnywhere,Category = "Input")
	class UInputAction* IA_ChaJump;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* cameraComp;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* springArm;
	
	//잡기범위
	UPROPERTY(EditAnywhere, Category = "Hold")
	float HoldRange = 50;

	void Move(const FInputActionValue& Values);
	void Look(const FInputActionValue& Values);
	void Jumping();
	//잡기
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void Holding();
	
	
	bool isOverlap = false;

};
