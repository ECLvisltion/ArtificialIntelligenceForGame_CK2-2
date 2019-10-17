#include "Miner.h"

int main()
{
	Miner miner(0, "°¡³ª´Ù");

	for (int i = 0; i < 100; i++)
	{
		miner.Update();
	}

	return 0;
}