#pragma once
#include "Pizza.h"

class CKStyleCheesePizza : public Pizza
{
public:
	CKStyleCheesePizza() : Pizza("CK Style Cheese Pizza") {}
	~CKStyleCheesePizza() {}

	int Cost() { return 7500; }
};
