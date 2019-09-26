#pragma once
#include "Pizza.h"

class NYStylePepperoniPizza : public Pizza
{
public:
	NYStylePepperoniPizza() : Pizza("Pepperoni Pizza") {}
	~NYStylePepperoniPizza() {}

	int Cost() { return 7800; }
};
