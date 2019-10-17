#pragma once
#include "BaseGameEntity.h"
#include "State.h"
using namespace std;

class Miner : public BaseGameEntity
{
private:
	State * currentState;
	int goldCarried;
	int moneyInBank;
	int fatigue;
	int thirst;

public:
	Miner(int id, string name);
	virtual ~Miner() {}

	void Update();
	void ChangeState(State * newState);

	void AddGold(int amount);
	void AddGoldBank();
	void AddFatigue(int amount);
	void RemoveFatigue();
	void RemoveThirst();

	int GetGoldCarried() { return goldCarried; }
	int GetMoneyInBank() { return moneyInBank; }
	int GetFatigue() { return fatigue; }
	int GetThirst() { return thirst; }
};

