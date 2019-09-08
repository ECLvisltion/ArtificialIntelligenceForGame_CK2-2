#pragma once
#include "Player.h"

class Defender : public Player
{
public:
	void Custom()
	{
		cout << "단단해보이게 생겼다." << endl;
	}
};
