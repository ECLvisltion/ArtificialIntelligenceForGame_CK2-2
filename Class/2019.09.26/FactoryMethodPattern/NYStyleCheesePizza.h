#pragma once
#include "Pizza.h"

class NYStyleCheesePizza : public Pizza
{
public:
	NYStyleCheesePizza() : Pizza("NY Style Cheese Pizza") {}
	~NYStyleCheesePizza() {}

	int Cost() { return 7200; }
};
