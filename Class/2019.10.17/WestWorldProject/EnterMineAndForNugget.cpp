#include "EnterMineAndForNugget.h"
#include "GoHomeAndSleepTillRested.h"
#include "QuenchThirst.h"
#include "VisitBankAndDepositGold.h"
#include <iostream>
using namespace std;

EnterMineAndForNugget::EnterMineAndForNugget()
{
}

EnterMineAndForNugget * EnterMineAndForNugget::GetInstance()
{
	static EnterMineAndForNugget * instance;
	if (instance == nullptr) { instance = new EnterMineAndForNugget(); }

	return instance;
}

void EnterMineAndForNugget::Player(Miner * miner)
{
	player = miner;
}

void EnterMineAndForNugget::Enter(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ±¤»ê¿¡ ÀÔÀåÇÏ¼Ì½À´Ï´Ù." << endl;
}

void EnterMineAndForNugget::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ±¤»ê¿¡¼­ ±¤¸ÆÀ» ¹ß°ßÇß½À´Ï´Ù." << endl;
	player->AddGold(1);

	if (player->GetThirst() >= 10) { miner->ChangeState(QuenchThirst::GetInstance()); }
	if (player->GetGoldCarried() >= 3) { miner->ChangeState(VisitBankAndDepositGold::GetInstance()); }
}

void EnterMineAndForNugget::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ±¤»ê¿¡¼­ ÅðÀåÇÏ¼Ì½À´Ï´Ù." << endl;
}
