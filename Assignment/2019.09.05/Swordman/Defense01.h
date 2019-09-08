#pragma once
#include "DefenseSkills.h"
#include <iostream>
using namespace std;

class Defense01 : public DefenseSkills
{
private:
	int DEF;
	int skillDEF = 50;
	float duration = 20.0f;

public:
	Defense01(int DEF)
	{
		this->DEF = DEF;
	}

	float FinalDamageReduce()
	{
		float nonSkillReduce = (float)DEF / (100.0f + (float)DEF);
		float skillReduce = ((float)DEF + (float)skillDEF) / (100.0f + ((float)DEF + (float)skillDEF));

		cout << "원래 스텟 데미지 감소율 : " << nonSkillReduce << '%' << endl;
		cout << "스킬 사용 시 " << duration << "초 동안 " << skillReduce << "% 감소함." << endl;

		return skillReduce;
	}
};
