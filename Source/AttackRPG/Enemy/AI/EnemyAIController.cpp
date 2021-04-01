// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "../EnemyCharacter.h"
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>
#include <Perception/AISenseConfig_Hearing.h>
#include <BehaviorTree/BlackboardComponent.h>
#include "../../AttackRPG.h"
#include <BehaviorTree/BehaviorTreeComponent.h>
#include <BehaviorTree/BehaviorTree.h>

AEnemyAIController::AEnemyAIController()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	//配置视觉信息

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;

	//听觉能力
	HearingConfig = CreateDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComp->ConfigureSense(*HearingConfig);
	PerceptionComp->ConfigureSense(*SightConfig);

	//PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetUpdatePerception);
}

void AEnemyAIController::OnPossess(APawn* PossessedPawn)
{
	Super::OnPossess(PossessedPawn);

	UBehaviorTree* Tree = LoadObject<UBehaviorTree>(nullptr, TEXT("BehaviorTree'/Game/BluePrints/Enemy/BT_Enemy.BT_Enemy'"));

	RunBehaviorTree(Tree);

	GetBlackboardComponent()->SetValueAsVector(TEXT("OriginPos"), PossessedPawn->GetActorLocation());
	GetBlackboardComponent()->SetValueAsVector(TEXT("PatrolPos"), PossessedPawn->GetActorLocation() + FVector::ForwardVector * 500);

	UE_LOG(LogTemp, Log, TEXT("===%s"), *GetBlackboardComponent()->GetValueAsVector(TEXT("PatrolPos")).ToString());
	bSetControlRotationFromPawnOrientation = false;

	TeamId = RPGTEAM::MonsterTeam;
}

void AEnemyAIController::OnUnPossess()
{
	Super::OnUnPossess();

	//停下行为树
	if (UBehaviorTreeComponent* BTComp = Cast<UBehaviorTreeComponent>(BrainComponent))
	{
		BTComp->StopTree();
	}
}

ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor & Other) const
{
	return IGenericTeamAgentInterface::GetTeamAttitudeTowards(Other);
}

FGenericTeamId AEnemyAIController::GetGenericTeamId() const
{

	/*if (AEnemyCharacter * Pawn = Cast<AEnemyCharacter>(GetPawn()))
	{
		return Pawn->GetGenericTeamID();
	}*/
	return FGenericTeamId();
}

void AEnemyAIController::OnTargetUpdatePerception(AActor * Actor, FAIStimulus Stimulus)
{
	if (Stimulus.Type == SightConfig->GetSenseID())
	{
		GetBlackboardComponent()->SetValueAsObject(TEXT("Target"), Actor);
	}
	else if (Stimulus.Type == HearingConfig->GetSenseID())
	{

	}
}
