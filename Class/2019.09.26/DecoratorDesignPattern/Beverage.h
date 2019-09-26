#pragma once
#include <iostream>
#include <string>
using namespace std;

class Beverage
{
private:
	string description;

public:
	Beverage() : description("Unknown Beverage") {}
	Beverage(string s) : description(s) {}
	~Beverage() {}

	virtual string GetDescription() { return description; }
	virtual double Cost() = 0;
};
