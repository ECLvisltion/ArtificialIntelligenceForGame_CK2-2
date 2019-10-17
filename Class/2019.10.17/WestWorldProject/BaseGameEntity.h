#pragma once
#include "Miner.h"
#include "State.h"
#include <string>
using namespace std;

class BaseGameEntity
{
private:
	string name;
	int id;

	void SetID(int val) { id = val; }
	void SetName(string val) { name = val; }

public:
	BaseGameEntity(int id, string name) { SetID(id); SetName(name); }
	virtual ~BaseGameEntity() {}

	virtual void Update() = 0;
	virtual void ChangeState(State * newState) = 0;
	int GetID() { return id; }
	string GetName() { return name; }
};
