#pragma once
#include "Quackable.h"
#include <iostream>
using namespace std;

class Quacking : public Quackable
{
public:
	void Quack() { cout << "�в�..." << endl; }
};
