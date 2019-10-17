#pragma once
#include "Miner.h"
#include "State.h"

class GoHomeAndSleepTillRested : public State
{
private:
	GoHomeAndSleepTillRested();
	Miner * player;

public:
	static GoHomeAndSleepTillRested * GetInstance();
	void Player(Miner * miner);
	void Enter(BaseGameEntity * miner);
	void Execute(BaseGameEntity * miner);
	void Exit(BaseGameEntity * miner);
};
