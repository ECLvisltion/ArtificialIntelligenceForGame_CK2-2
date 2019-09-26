#pragma once
#include "CondimentDecorator.h"

class Whip : public CondimentDecorator
{
private:
	Beverage * beverage;

public:
	Whip() {}
	Whip(Beverage * b) : beverage(b) {}
	~Whip() {}

	string GetDescription() { return beverage->GetDescription() + " + Whip"; }
	double Cost() { return beverage->Cost() + 1000.0; }
};
