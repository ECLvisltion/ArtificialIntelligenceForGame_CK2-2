#pragma once
#include "BaseState.h"
#include <ctime>

class BaseTrafficLight;

class YellowState : public BaseState
{
private:
	clock_t oldTime, currentTime;
	YellowState();

public:
	~YellowState();

	// getter
	static YellowState * GetInstance();

	void Enter(BaseTrafficLight * currentState);
	void Execute(BaseTrafficLight * currentState);
	void Exit(BaseTrafficLight * currentState);
};

