#pragma once
#include "Beverage.h"

class HouseBlend : public Beverage
{
public:
	HouseBlend() : Beverage("House Blend") {}
	~HouseBlend() {}

	double Cost() { return 3500.0; }
};
