#include "Miner.h"

int main()
{
	Miner miner(0, "������");

	for (int i = 0; i < 100; i++)
	{
		miner.Update();
	}

	return 0;
}