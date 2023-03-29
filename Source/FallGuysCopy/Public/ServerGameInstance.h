// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "ServerGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class FALLGUYSCOPY_API UServerGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UServerGameInstance();
	virtual void Init() override;

	FName sessionID;
	IOnlineSessionPtr sessionInterface;
	TSharedPtr<FOnlineSessionSearch> sessionSearch;

public:
	UFUNCTION()
	void CreateMySession(FString roomName, int32 playerCount);
	UFUNCTION()
	void FindMySession();
	UFUNCTION()
	void JoinMySession(int32 sessionIdx);
	UFUNCTION()
	void OnCreateSessionComplete(FName sessionName, bool bisSuccess);
};
