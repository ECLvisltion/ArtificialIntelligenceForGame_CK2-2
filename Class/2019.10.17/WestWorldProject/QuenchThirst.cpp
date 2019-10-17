#include "EnterMineAndForNugget.h"
#include "GoHomeAndSleepTillRested.h"
#include "QuenchThirst.h"
#include "VisitBankAndDepositGold.h"
#include <iostream>
using namespace std;

QuenchThirst::QuenchThirst()
{
}

QuenchThirst * QuenchThirst::GetInstance()
{
	static QuenchThirst * instance;
	if (instance == nullptr) { instance = new QuenchThirst(); }

	return instance;
}

void QuenchThirst::Player(Miner * miner)
{
	player = miner;
}

void QuenchThirst::Enter(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 식수대에 입장하셨습니다." << endl;
}

void QuenchThirst::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 식수대에서 갈증을 해소하셨습니다" << endl;
	player->RemoveThirst();

	if (player->GetThirst() == 0) { miner->ChangeState(EnterMineAndForNugget::GetInstance()); }
}

void QuenchThirst::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 식수대에서 퇴장하셨습니다." << endl;
}
