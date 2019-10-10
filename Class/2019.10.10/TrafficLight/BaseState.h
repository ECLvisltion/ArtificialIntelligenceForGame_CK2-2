#pragma once

class BaseTrafficLight; // Super class of all states

class BaseState
{
public:
	BaseState() {}
	~BaseState() {}

	virtual void Enter(BaseTrafficLight *) = 0;
	virtual void Execute(BaseTrafficLight *) = 0;
	virtual void Exit(BaseTrafficLight *) = 0;
};
