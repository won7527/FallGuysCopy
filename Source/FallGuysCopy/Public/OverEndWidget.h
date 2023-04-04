// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OverEndWidget.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API UOverEndWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void PlayAnimationByName();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* OverAnimation;
};
