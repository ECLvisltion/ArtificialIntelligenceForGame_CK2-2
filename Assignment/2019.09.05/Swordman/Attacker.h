#pragma once
#include "Player.h"

class Attacker : public Player
{
public:
	void Custom()
	{
		cout << "아파보이게 생겼다." << endl;
	}
};
