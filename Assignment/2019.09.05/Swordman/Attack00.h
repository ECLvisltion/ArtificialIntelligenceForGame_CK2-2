#pragma once
#include "AttackSkills.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Attack00 : public AttackSkills
{
private:
	int minATK, maxATK;
	float damagePercentage = 1.5f;
	int hitCount = 3;

public:
	Attack00(int minATK, int maxATK)
	{
		this->minATK = minATK;
		this->maxATK = maxATK;
	}

	int FinalDamage()
	{
		srand((unsigned)time(NULL));

		int total = 0;

		for (int i = 1; i <= hitCount; i++)
		{
			int damageGap = maxATK - minATK;
			int damage = (minATK + (rand() % damageGap)) * damagePercentage;
			cout << "스킬 " << i << "타 데미지 : " << damage << endl;
			total += damage;
		}

		cout << "총 스킬 데미지 : " << total << endl;

		return total;
	}
};
