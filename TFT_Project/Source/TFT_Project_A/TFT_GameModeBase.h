// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "TFT_GameModeBase.generated.h"


UCLASS()
class TFT_PROJECT_A_API ATFT_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ATFT_GameModeBase();

	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	UFUNCTION()
	void SetPlayerKnight();
	UFUNCTION()
	void SetPlayerArcher();

	UFUNCTION()
	void SetPlayerDH();
	UFUNCTION()
	void SetPlayerCG();
	UFUNCTION()
	void SetPlayerBJ();
	UFUNCTION()
	void SetPlayerIY();

	UFUNCTION()
	void SetPlayerTest();

	void MouseLock();
private:
	UPROPERTY()
	class UTFT_JobChoice* JobSelectionWidgetInstance;

	TSubclassOf<APawn> _knight;
	TSubclassOf<APawn> _archer;

	TSubclassOf<APawn> _dh;
	TSubclassOf<APawn> _cg;
	TSubclassOf<APawn> _bj;
	TSubclassOf<APawn> _iy;

	TSubclassOf<APawn> _testM;
};
