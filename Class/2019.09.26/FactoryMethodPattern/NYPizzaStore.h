#pragma once
#include "PizzaStore.h"
#include "NYStyleCheesePizza.h"
#include "NYStylePepperoniPizza.h"

class NYPizzaStore : public PizzaStore
{
public:
	NYPizzaStore() {}
	~NYPizzaStore() {}

	Pizza * CreatePizza(string type)
	{
		if (type == "Cheese")
			return new NYStyleCheesePizza();
		else if (type == "Pepperoni")
			return new NYStylePepperoniPizza();
		else
			return NULL;
	}
};
