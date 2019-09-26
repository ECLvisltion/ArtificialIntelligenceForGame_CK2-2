#pragma once
#include "CondimentDecorator.h"

class Mocha : public CondimentDecorator
{
private:
	Beverage * beverage;

public:
	Mocha() {}
	Mocha(Beverage * b) : beverage(b) {}
	~Mocha() {}

	string GetDescription() { return beverage->GetDescription() + " + Mocha"; }
	double Cost() { return beverage->Cost() + 1000.0; }
};
