#pragma once
#include "Quackable.h"
#include <iostream>
using namespace std;

class Quacking : public Quackable
{
public:
	void Quack() { cout << "²Ð²Ð..." << endl; }
};
