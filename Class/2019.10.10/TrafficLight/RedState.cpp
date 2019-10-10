#include "BaseTrafficLight.h"
#include "GreenState.h"
#include "RedState.h"
#include "YellowState.h"
#include <iostream>
using namespace std;

RedState::RedState()
{
}

RedState::~RedState()
{
}

RedState * RedState::GetInstance()
{
	static RedState * instance;
	if (instance == nullptr) { instance = new RedState(); }

	return instance;
}

void RedState::Enter(BaseTrafficLight * currentState)
{
	oldTime = clock();
	cout << "빨간 불이 켜진다." << endl;
}

void RedState::Execute(BaseTrafficLight * currentState)
{
	currentTime = clock();
	cout << "빨간 불 : 멈추시오." << endl;
	if (currentTime - oldTime >= 10000) { currentState->ChangeState(GreenState::GetInstance()); }
}

void RedState::Exit(BaseTrafficLight * currentState)
{
	cout << "빨간 불이 꺼진다." << endl;
}
