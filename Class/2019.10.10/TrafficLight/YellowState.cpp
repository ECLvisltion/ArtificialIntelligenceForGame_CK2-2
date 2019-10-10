#include "BaseTrafficLight.h"
#include "GreenState.h"
#include "RedState.h"
#include "YellowState.h"
#include <iostream>
using namespace std;

YellowState::YellowState()
{
}

YellowState::~YellowState()
{
}

YellowState * YellowState::GetInstance()
{
	static YellowState * instance;
	if (instance == nullptr) { instance = new YellowState; }

	return instance;
}

void YellowState::Enter(BaseTrafficLight * currentState)
{
	oldTime = clock();
	cout << "노란 불이 켜진다." << endl;
}

void YellowState::Execute(BaseTrafficLight * currentState)
{
	currentTime = clock();
	cout << "노란 불 : 빨리 지나가거나 미리 멈추시오." << endl;
	if (currentTime - oldTime >= 2000) { currentState->ChangeState(RedState::GetInstance()); }
}

void YellowState::Exit(BaseTrafficLight * currentState)
{
	cout << "노란 불이 꺼진다." << endl;
}
