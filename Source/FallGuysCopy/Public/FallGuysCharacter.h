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
	virtual void PostInitializeComponents() override;
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

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Dash;

	UPROPERTY(EditAnywhere, Category = "Input")
		class UInputAction* IA_Hold;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* cameraComp;
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* springArm;

	class UPlayerAnim* PlayerAnim;
	
	UPROPERTY(EditAnywhere)
		class UWidgetComponent* PlayerInfo;
	
	//잡기범위
	UPROPERTY(EditAnywhere, Category = "Hold")
	float HoldRange = 50;

	void Move(const FInputActionValue& Values);
	void MoveEnd();
	void Look(const FInputActionValue& Values);
	void Jumping();
	void StopJumping();
	void Holding();
	void Dash();
	void Release();

	//잡기
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	
	bool isOverlap = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float DashPower = 400;	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float FallingTime = 1.0f;

	UPROPERTY()
		float CoolTime;
	
	UPROPERTY()
		FVector StartLoc;
	UPROPERTY()
		FVector EndLoc;


	UPROPERTY()
		bool IsCool;

	UPROPERTY(Replicated)
		FString PlayerName;

	UPROPERTY()
		float Timer;
	
	UPROPERTY(Replicated)
		int32 AllPlayerNum;
	UPROPERTY(Replicated)
		int32 GameOverPlayerNum;

	bool IsMain;
	

	UPROPERTY()
		class UServerGameInstance* GameInstance;

	UPROPERTY()
		class UPlayerInfoWidget* InfoWidget;
	UPROPERTY()
		class AFallGuysPlayerController* PlayerController;
	
	
	UFUNCTION(Server, Unreliable)
		void ServerSetName(const FString& name);	
	
	UFUNCTION(Server, Unreliable)
		void ServerSetTimer(float GameTime);
	UFUNCTION(NetMulticast, Unreliable)
		void MulticastSetTimer(float GameTime);
	
	UFUNCTION(Server, Unreliable)
		void ServerSetDeadNum();


	void SetPlayerNum(int32 GameOverNum, int32 AllNum);

	class APointActor* PointActor;

};
