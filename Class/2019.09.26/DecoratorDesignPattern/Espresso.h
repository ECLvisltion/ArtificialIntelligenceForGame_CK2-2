#pragma once
#include "Beverage.h"

class Espresso : public Beverage
{
public:
	Espresso() : Beverage("Espresso") {}
	~Espresso() {}

	double Cost() { return 3000.0; }
};
