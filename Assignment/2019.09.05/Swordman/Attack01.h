#pragma once
#include "AttackSkills.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Attack01 : public AttackSkills
{
private:
	int minATK, maxATK;
	float damagePercentage = 2.5f;

public:
	Attack01(int minATK, int maxATK)
	{
		this->minATK = minATK;
		this->maxATK = maxATK;
	}

	int FinalDamage()
	{
		srand((unsigned)time(NULL));

		int damageGap = maxATK - minATK;
		int damage = (minATK + (rand() % damageGap)) * damagePercentage;

		cout << "스킬 데미지 : " << damage << endl;

		return damage;
	}
};
