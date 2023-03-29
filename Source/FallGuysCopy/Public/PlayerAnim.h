// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnim.generated.h"

UCLASS()
class FALLGUYSCOPY_API UPlayerAnim : public UAnimInstance
{
	GENERATED_BODY()
	


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsJump;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsFall;	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsDive;
	UFUNCTION()
		void AnimNotify_JumpEnd();
};
