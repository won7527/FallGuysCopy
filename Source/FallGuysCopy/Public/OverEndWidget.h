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

	virtual void NativeConstruct() override;

	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* OverAnimation;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, meta = (BindWidget))
	class UButton* btn_Quit;

	UFUNCTION()
	void QuitGame();

	void PlayAnimationByName();

};
