#include "BaseTrafficLight.h"
#include "GreenState.h"
#include "RedState.h"
#include "YellowState.h"
#include <iostream>
using namespace std;

GreenState::GreenState()
{
}

GreenState::~GreenState()
{
}

GreenState * GreenState::GetInstance()
{
	static GreenState * instance;
	if (instance == nullptr) { instance = new GreenState; }

	return instance;
}

void GreenState::Enter(BaseTrafficLight * currentState)
{
	oldTime = clock();
	cout << "초록 불이 켜진다." << endl;
}

void GreenState::Execute(BaseTrafficLight * currentState)
{
	currentTime = clock();
	cout << "초록 불 : 지나가시오." << endl;
	if (currentTime - oldTime >= 8000) { currentState->ChangeState(YellowState::GetInstance()); }
}

void GreenState::Exit(BaseTrafficLight * currentState)
{
	cout << "초록 불이 꺼진다." << endl;
}
