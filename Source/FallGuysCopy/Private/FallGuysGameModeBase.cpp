// Fill out your copyright notice in the Description page of Project Settings.


#include "FallGuysGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "EndingWidget.h"
#include "LoginWidget.h"
#include "OverEndWidget.h"
#include "VictoryWidget.h"




void AFallGuysGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ending_UI = CreateWidget<UEndingWidget> (GetWorld(), ending);
	//login_UI = CreateWidget<ULoginWidget>(GetWorld(), loging);
	gameOver_UI = CreateWidget<UOverEndWidget>(GetWorld(), gameOver);
	victory_UI = CreateWidget<UVictoryWidget>(GetWorld(), victoring);
	//if (login_UI != nullptr)
	//{
	//	login_UI->AddToViewport();
	//}
	

}

void AFallGuysGameModeBase::Ending()
{
	if (ending_UI != nullptr)
	{
		ending_UI->AddToViewport();
		ending_UI->PlayAnimationByName();
	}
}

void AFallGuysGameModeBase::GameOverEnding()
{
	if (gameOver_UI != nullptr)
	{
		gameOver_UI->AddToViewport();
		gameOver_UI->PlayAnimationByName();
	}
}

void AFallGuysGameModeBase::VictoryEnding()
{
	if (victory_UI != nullptr)
	{
		victory_UI->AddToViewport();
		victory_UI->PlayAnimationByName();
	}
}
