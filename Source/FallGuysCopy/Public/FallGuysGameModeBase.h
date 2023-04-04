// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FallGuysGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API AFallGuysGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;


public:
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UEndingWidget> ending;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ULoginWidget> loging;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UOverEndWidget> gameOver;
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UVictoryWidget> victoring;



	UPROPERTY()
	class UEndingWidget* ending_UI;

	UPROPERTY()
	class ULoginWidget* login_UI;

	UPROPERTY()
	class UOverEndWidget* gameOver_UI;

	UPROPERTY()
	class UVictoryWidget* victory_UI;

	void Ending();
	void GameOverEnding();
	void VictoryEnding();

};
