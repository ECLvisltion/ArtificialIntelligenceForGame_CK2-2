#pragma once
#include "Miner.h"
#include "State.h"

class VisitBankAndDepositGold : public State
{
private:
	VisitBankAndDepositGold();
	Miner * player;

public:
	static VisitBankAndDepositGold * GetInstance();
	void Player(Miner * miner);
	void Enter(BaseGameEntity * miner);
	void Execute(BaseGameEntity * miner);
	void Exit(BaseGameEntity * miner);
};
