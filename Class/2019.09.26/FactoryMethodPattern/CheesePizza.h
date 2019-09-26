#pragma once
#include "Pizza.h"

class CheesePizza : public Pizza
{
public:
	CheesePizza() : Pizza("Cheese Pizza") {}
	~CheesePizza() {}

	int Cost() { return 5000; }
};
