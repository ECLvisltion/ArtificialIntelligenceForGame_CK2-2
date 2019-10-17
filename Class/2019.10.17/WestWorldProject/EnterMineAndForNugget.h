#pragma once
#include "Miner.h"
#include "State.h"

class EnterMineAndForNugget : public State
{
private:
	EnterMineAndForNugget();
	Miner * player;

public:
	static EnterMineAndForNugget * GetInstance();
	void Player(Miner * miner);
	void Enter(BaseGameEntity * miner);
	void Execute(BaseGameEntity * miner);
	void Exit(BaseGameEntity * miner);
};
