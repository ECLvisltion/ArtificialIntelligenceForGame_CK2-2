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
	cout << miner->GetName() << " : 집에 입장하셨습니다." << endl;
}

void GoHomeAndSleepTillRested::Execute(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 집에서 휴식을 취하셨습니다." << endl;
	player->RemoveFatigue();

	miner->ChangeState(EnterMineAndForNugget::GetInstance());
}

void GoHomeAndSleepTillRested::Exit(BaseGameEntity * miner)
{
	cout << miner->GetName() << " : 집에서 퇴장하셨습니다." << endl;
}
