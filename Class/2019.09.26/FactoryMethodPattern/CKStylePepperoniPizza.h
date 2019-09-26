#pragma once
#include "Pizza.h"

class CKStylePepperoniPizza : public Pizza
{
public:
	CKStylePepperoniPizza() : Pizza("CK Style Pepperoni Pizza") {}
	~CKStylePepperoniPizza() {}

	int Cost() { return 8000; }
};
