#pragma once
#include "Miner.h"
#include "State.h"

class QuenchThirst : public State
{
private:
	QuenchThirst();
	Miner * player;

public:
	static QuenchThirst * GetInstance();
	void Player(Miner * miner);
	void Enter(BaseGameEntity * miner);
	void Execute(BaseGameEntity * miner);
	void Exit(BaseGameEntity * miner);
};
