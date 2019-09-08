#include "Attack00.h"
#include "Attack01.h"
#include "Attacker.h"
#include "AttackSkills.h"
#include "Defender.h"
#include "Defense00.h"
#include "Defense01.h"
#include "DefenseSkills.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main()
{
	Player* player00 = new Attacker();

	player00->SetATK(200);
	player00->SetDEF(50);

	AttackSkills* player00_atkSkill = new Attack00(player00->GetMinATK(), player00->GetMaxATK());
	DefenseSkills* player00_defSkill = new Defense00(player00->GetDEF());

	player00->SetAttackSkill(player00_atkSkill);
	player00->SetDefenseSkill(player00_defSkill);

	player00->Custom();
	player00->NormalAttack();
	player00->SkillAttack();
	player00->SkillDefense();

	cout << "--------------------------------------------------" << endl;

	Player* player01 = new Defender();

	player01->SetATK(50);
	player01->SetDEF(200);

	AttackSkills* player01_atkSkill = new Attack01(player01->GetMinATK(), player01->GetMaxATK());
	DefenseSkills* player01_defSkill = new Defense01(player01->GetDEF());

	player01->SetAttackSkill(player01_atkSkill);
	player01->SetDefenseSkill(player01_defSkill);

	player01->Custom();
	player01->NormalAttack();
	player01->SkillAttack();
	player01->SkillDefense();

	delete player00, player01, player00_atkSkill, player00_defSkill, player01_atkSkill, player01_defSkill;

	return 0;
}
