#include "BaseState.h"
#include "RedState.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight()
{
	// 처음으로 설정되는 불빛
	currentState = RedState::GetInstance();
	currentState->Enter(this);
}

TrafficLight::~TrafficLight()
{
}

void TrafficLight::Update()
{
	currentState->Execute(this);
}

void TrafficLight::ChangeState(BaseState * newState)
{
	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}
