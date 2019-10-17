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
	cout << miner->GetName() << " : 은행에 입장하셨습니다." << endl;
}

void VisitBankAndDepositGold::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 은행에 입금하셨습니다." << endl;
	player->AddGoldBank();

	if (player->GetMoneyInBank() <= 30) { miner->ChangeState(EnterMineAndForNugget::GetInstance()); }
	else { miner->ChangeState(GoHomeAndSleepTillRested::GetInstance()); }
}

void VisitBankAndDepositGold::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 은행에서 퇴장하셨습니다." << endl;
}
