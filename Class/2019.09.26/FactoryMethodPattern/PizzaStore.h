#pragma once
#include "PizzaFactory.h"

class PizzaStore// : public PizzaFactory
{
public:
	PizzaStore() {}
	~PizzaStore() {}

	Pizza * OrderPizza(string type)
	{
		Pizza * pizza = CreatePizza(type);
		pizza->Prepare();
		pizza->Bake();
		pizza->Cut();
		pizza->Box();

		return pizza;
	}

	virtual Pizza * CreatePizza(string type) = 0;
};
