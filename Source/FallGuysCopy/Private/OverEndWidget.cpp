// Fill out your copyright notice in the Description page of Project Settings.


#include "OverEndWidget.h"
#include "Components/Button.h"
#include <Kismet/KismetSystemLibrary.h>
#include <Kismet/GameplayStatics.h>


void UOverEndWidget::NativeConstruct()
{
	btn_Quit->OnClicked.AddDynamic(this, &UOverEndWidget::QuitGame);
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
}

void UOverEndWidget::PlayAnimationByName()
{
	PlayAnimation(OverAnimation);
}



void UOverEndWidget::QuitGame()
{
	APlayerController* playerCon = GetWorld()->GetFirstPlayerController();
	UKismetSystemLibrary::QuitGame(GetWorld(), playerCon, EQuitPreference::Quit, true);
}
