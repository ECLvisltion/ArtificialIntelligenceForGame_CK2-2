#include "Beverage.h"
#include "CondimentDecorator.h"
#include "DarkRoast.h"
#include "Espresso.h"
#include "HouseBlend.h"
#include "Milk.h"
#include "Mocha.h"
#include "Whip.h"
#include <iostream>
using namespace std;

int main()
{
	Beverage * espresso = new Espresso();
	cout << "Order : " << espresso->GetDescription() << ", Cost : " << espresso->Cost() << "Won" << endl;

	Beverage * darkRoast = new DarkRoast();
	darkRoast = new Milk(darkRoast);
	cout << "Order : " << darkRoast->GetDescription() << ", Cost : " << darkRoast->Cost() << "Won" << endl;

	Beverage * houseBlend = new HouseBlend();
	houseBlend = new Mocha(houseBlend);
	houseBlend = new Whip(houseBlend);
	cout << "Order : " << houseBlend->GetDescription() << ", Cost : " << houseBlend->Cost() << "Won" << endl;

	delete espresso, darkRoast, houseBlend;

	return 0;
}