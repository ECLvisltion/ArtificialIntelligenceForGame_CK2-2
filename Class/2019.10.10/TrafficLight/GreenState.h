#pragma once
#include "BaseState.h"
#include <ctime>

class GreenState : public BaseState
{
private:
	clock_t oldTime, currentTime;
	GreenState();

public:
	~GreenState();

	// getter
	static GreenState * GetInstance();

	void Enter(BaseTrafficLight * currentState);
	void Execute(BaseTrafficLight * currentState);
	void Exit(BaseTrafficLight * currentState);
};
