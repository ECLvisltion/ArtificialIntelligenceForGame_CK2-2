#include "EnterMineAndForNugget.h"
#include "GoHomeAndSleepTillRested.h"
#include "QuenchThirst.h"
#include "VisitBankAndDepositGold.h"
#include <iostream>
using namespace std;

GoHomeAndSleepTillRested::GoHomeAndSleepTillRested()
{
}

GoHomeAndSleepTillRested * GoHomeAndSleepTillRested::GetInstance()
{
	static GoHomeAndSleepTillRested * instance;
	if (instance == nullptr) { instance = new GoHomeAndSleepTillRested(); }

	return instance;
}

void GoHomeAndSleepTillRested::Player(Miner * miner)
{
	player = miner;
}

void GoHomeAndSleepTillRested::Enter(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ���� �����ϼ̽��ϴ�." << endl;
}

void GoHomeAndSleepTillRested::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ������ �޽��� ���ϼ̽��ϴ�." << endl;
	player->RemoveFatigue();

	miner->ChangeState(EnterMineAndForNugget::GetInstance());
}

void GoHomeAndSleepTillRested::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : ������ �����ϼ̽��ϴ�." << endl;
}
