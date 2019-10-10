#pragma once
#include "BaseTrafficLight.h"

class BaseState;

class TrafficLight : public BaseTrafficLight
{
private:
	BaseState * currentState;

public:
	TrafficLight();
	~TrafficLight();

	void Update();
	void ChangeState(BaseState * newState);
};
