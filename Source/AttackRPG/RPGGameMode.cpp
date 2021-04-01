// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameMode.h"
#include "GenericTeamAgentInterface.h"
#include "AttackRPG.h"

ARPGGameMode::ARPGGameMode()
{
	
}

void ARPGGameMode::BeginPlay()
{
	//�޸���Ӫ�ȽϹ�ϵ
	FGenericTeamId::SetAttitudeSolver([](FGenericTeamId A, FGenericTeamId B) {

		if (A == RPGTEAM::NeutralTeam || B == RPGTEAM::NeutralTeam)
		{
			return ETeamAttitude::Neutral;
		}
		if (A != B)
		{
			return ETeamAttitude::Hostile;
		}
		if (A == B)
		{
			return ETeamAttitude::Friendly;
		}

		return ETeamAttitude::Neutral;
	});//ʹ����������

}
