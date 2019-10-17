#include "EnterMineAndForNugget.h"
#include "Miner.h"

Miner::Miner(int id, string name) : BaseGameEntity(id, name)
{
	goldCarried = 0;
	moneyInBank = 0;
	fatigue = 0;
	thirst = 0;
	currentState = EnterMineAndForNugget::GetInstance();
	currentState->Player(this);
}

void Miner::Update()
{
	thirst++;
	currentState->Execute(this);
}

void Miner::ChangeState(State * newState)
{
	currentState->Exit(this);
	currentState = newState;
	currentState->Player(this);
	currentState->Enter(this);
}

void Miner::AddGold(int amount)
{
	goldCarried += amount;
}

void Miner::AddGoldBank()
{
	moneyInBank += goldCarried;
	goldCarried = 0;
}

void Miner::AddFatigue(int amount)
{
	fatigue += amount;
}

void Miner::RemoveFatigue()
{
	fatigue = 0;
}

void Miner::RemoveThirst()
{
	thirst = 0;
}
