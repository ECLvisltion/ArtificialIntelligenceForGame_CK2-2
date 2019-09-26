#pragma once
#include "Pizza.h"

class PepperoniPizza : public Pizza
{
public:
	PepperoniPizza() : Pizza("Pepperoni Pizza") {}
	~PepperoniPizza() {}

	int Cost() { return 5500; }
};
