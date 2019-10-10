#pragma once

class BaseState; // Super class of traffic light

class BaseTrafficLight
{
public:
	BaseTrafficLight() {}
	~BaseTrafficLight() {}

	virtual void Update() = 0;
	virtual void ChangeState(BaseState * newState) = 0;
};
