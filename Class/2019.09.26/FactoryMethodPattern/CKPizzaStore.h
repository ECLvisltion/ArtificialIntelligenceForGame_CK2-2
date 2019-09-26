#pragma once
#include "PizzaStore.h"
#include "CKStyleCheesePizza.h"
#include "CKStylePepperoniPizza.h"

class CKPizzaStore : public PizzaStore
{
public:
	CKPizzaStore() {}
	~CKPizzaStore() {}

	Pizza * CreatePizza(string type)
	{
		if (type == "Cheese")
			return new CKStyleCheesePizza();
		else if (type == "Pepperoni")
			return new CKStylePepperoniPizza();
		else
			return NULL;
	}
};
