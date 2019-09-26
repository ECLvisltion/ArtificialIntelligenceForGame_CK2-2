#pragma once
#include <string>
using namespace std;

class Pizza
{
private:
	string pizzaName;
	bool isPrepare = false, isBake = false, isCut = false, isBox = false;

public:
	Pizza() : pizzaName("Unknown Pizza") {}
	Pizza(string pizzaName) : pizzaName(pizzaName) {}
	~Pizza() {}

	virtual string GetPizzaName() { return pizzaName; }
	virtual int Cost() = 0;

	void Prepare();
	void Bake();
	void Cut();
	void Box();
};
