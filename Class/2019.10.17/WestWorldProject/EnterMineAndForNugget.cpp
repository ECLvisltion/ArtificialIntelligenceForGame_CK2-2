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
	cout << miner->GetName() << " : ���꿡 �����ϼ̽��ϴ�." << endl;
}

void EnterMineAndForNugget::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���꿡�� ������ �߰��߽��ϴ�." << endl;
	player->AddGold(1);

	if (player->GetThirst() >= 10) { miner->ChangeState(QuenchThirst::GetInstance()); }
	if (player->GetGoldCarried() >= 3) { miner->ChangeState(VisitBankAndDepositGold::GetInstance()); }
}

void EnterMineAndForNugget::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���꿡�� �����ϼ̽��ϴ�." << endl;
}
