#pragma once
#include "Flyable.h"
#include <iostream>
using namespace std;

class FlyWithWings : public Flyable
{
public:
	void Fly() { cout << "ÆÛ´öÆÛ´ö..." << endl; }
};
