// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include <Perception/AIPerceptionTypes.h>
#include "EnemyAIController.generated.h"

class UAIPerceptionComponent;
class UAISenseConfig_Sight;
class UAISenseConfig_Hearing;
/**
 * 
 */
UCLASS()
class ATTACKRPG_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

		AEnemyAIController();

protected:

	virtual void OnPossess(APawn* PossessedPawn) override;

	virtual void OnUnPossess() override;

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const;

	virtual FGenericTeamId GetGenericTeamId() const override;

	UFUNCTION()
		void OnTargetUpdatePerception(AActor* Actor, FAIStimulus Stimulus); //���¸�֪����ٵ�����
protected:
	FGenericTeamId TeamId;

	UPROPERTY(VisibleAnywhere)
		UAIPerceptionComponent* PerceptionComp;
	UPROPERTY()
		UAISenseConfig_Sight* SightConfig;
	UPROPERTY()
		UAISenseConfig_Hearing* HearingConfig;

};
