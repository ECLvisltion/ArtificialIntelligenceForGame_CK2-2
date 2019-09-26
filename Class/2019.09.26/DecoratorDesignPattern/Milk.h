#pragma once
#include "CondimentDecorator.h"

class Milk : public CondimentDecorator
{
private:
	Beverage * beverage;

public:
	Milk() {}
	Milk(Beverage * b) : beverage(b) {}
	~Milk() {}

	string GetDescription() { return beverage->GetDescription() += " + Milk"; }
	double Cost() { return beverage->Cost() + 1000.0; }
};
