#pragma once
#include "Flyable.h"
#include "Quackable.h"
#include <iostream>
using namespace std;

class Duck
{
private:
	Flyable * flyable;
	Quackable * quackable;

public:
	// setter
	void SetFly(Flyable *fa) { flyable = fa; }
	void SetQuack(Quackable *qa) { quackable = qa; }

	void Swim() { cout << "รทบกรทบก..." << endl; }
	void PerformFly() { flyable->Fly(); }
	void PerformQuack() { quackable->Quack(); }

	virtual void Draw() = 0;
};
