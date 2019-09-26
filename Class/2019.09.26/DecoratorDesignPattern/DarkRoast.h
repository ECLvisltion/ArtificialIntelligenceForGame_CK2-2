#pragma once
#include "Beverage.h"

class DarkRoast : public Beverage
{
public:
	DarkRoast() : Beverage("Dark Roast") {}
	~DarkRoast() {}

	double Cost() { return 3500.0; }
};
