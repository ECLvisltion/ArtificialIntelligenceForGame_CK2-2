#pragma once
#include "AttackSkills.h"
#include "DefenseSkills.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

class Player
{
private:
	AttackSkills* attackSkills;
	DefenseSkills* defenseSkills;
	int ATK, DEF;
	int minATK, maxATK;

public:
	Player(int ATK = 100, int DEF = 100)
	{
		this->ATK = ATK;
		this->DEF = DEF;
		SetMinMax();
		attackSkills = NULL;
		defenseSkills = NULL;
	}

	// setter
	void SetAttackSkill(AttackSkills* as) { attackSkills = as; }
	void SetDefenseSkill(DefenseSkills* ds) { defenseSkills = ds; }
	void SetATK(int atk) { ATK = atk; SetMinMax(); }
	void SetDEF(int def) { DEF = def; }
	void SetMinMax() { minATK = (float)ATK * 0.9f, maxATK = (float)ATK * 1.1f; }

	// getter
	int GetATK() { return ATK; }
	int GetDEF() { return DEF; }
	int GetMinATK() { return minATK; }
	int GetMaxATK() { return maxATK; }

	float NormalAttack()
	{
		srand((unsigned)time(NULL));

		int damageGap = maxATK - minATK;
		int damage = (minATK + (rand() % damageGap));

		cout << "기본공격 데미지 : " << damage << endl;

		return damage;
	}
	int SkillAttack()
	{
		if (attackSkills == NULL)
		{
			cout << "공격스킬이 없습니다." << endl;
			return -1;
		}

		int totalDamage = attackSkills->FinalDamage();

		return totalDamage;
	}
	float SkillDefense()
	{
		if (defenseSkills == NULL)
		{
			cout << "방어스킬이 없습니다." << endl;
			return -1;
		}

		float reduceDamage = defenseSkills->FinalDamageReduce();

		return reduceDamage;
	}

	virtual void Custom() = 0;
};
