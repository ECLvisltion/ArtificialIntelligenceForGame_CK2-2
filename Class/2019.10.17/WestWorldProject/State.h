#pragma once

class BaseGameEntity;
class Miner;

class State
{
public:
	virtual ~State() {}

	virtual void Player(Miner *) = 0;
	virtual void Enter(BaseGameEntity *) = 0;
	virtual void Execute(BaseGameEntity *) = 0;
	virtual void Exit(BaseGameEntity *) = 0;
};
