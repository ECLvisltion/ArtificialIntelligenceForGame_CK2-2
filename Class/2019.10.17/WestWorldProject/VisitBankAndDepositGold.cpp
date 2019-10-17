#include "EnterMineAndForNugget.h"
#include "GoHomeAndSleepTillRested.h"
#include "QuenchThirst.h"
#include "VisitBankAndDepositGold.h"
#include <iostream>
using namespace std;

VisitBankAndDepositGold::VisitBankAndDepositGold()
{
}

VisitBankAndDepositGold * VisitBankAndDepositGold::GetInstance()
{
	static VisitBankAndDepositGold * instance;
	if (instance == nullptr) { instance = new VisitBankAndDepositGold(); }

	return instance;
}

void VisitBankAndDepositGold::Player(Miner * miner)
{
	player = miner;
}

void VisitBankAndDepositGold::Enter(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���࿡ �����ϼ̽��ϴ�." << endl;
}

void VisitBankAndDepositGold::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���࿡ �Ա��ϼ̽��ϴ�." << endl;
	player->AddGoldBank();

	if (player->GetMoneyInBank() <= 30) { miner->ChangeState(EnterMineAndForNugget::GetInstance()); }
	else { miner->ChangeState(GoHomeAndSleepTillRested::GetInstance()); }
}

void VisitBankAndDepositGold::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���࿡�� �����ϼ̽��ϴ�." << endl;
}
