#pragma once
#include "Quackable.h"
#include <iostream>
using namespace std;

class QuackingLoud : public Quackable
{
public:
	void Quack() { cout << "�ٿ��ٿ�..." << endl; }
};
