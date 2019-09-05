#pragma once
#include "Flyable.h"
#include <iostream>
using namespace std;

class FlyWithBigWings :	public Flyable
{
public:
	void Fly() { cout << "ÆÞ·°ÆÞ·°..." << endl; }
};
