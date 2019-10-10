#pragma once
#include "BaseState.h"
#include <ctime>

class BaseTrafficLight;

class RedState : public BaseState
{
private:
	clock_t oldTime, currentTime;
	RedState(); // for singleton pattern

public:
	~RedState();
	
	// getter
	static RedState * GetInstance();

	void Enter(BaseTrafficLight * currentState);
	void Execute(BaseTrafficLight * currentState);
	void Exit(BaseTrafficLight * currentState);
};
