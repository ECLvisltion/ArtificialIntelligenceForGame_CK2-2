#include "CurrentConditionDisplay.h"
#include <iostream>
using namespace std;

CurrentConditionDisplay::CurrentConditionDisplay()
{
}

CurrentConditionDisplay::CurrentConditionDisplay(Subject * w)
{
	wServer = w;
	wServer->RegisterObserver(this);
}

CurrentConditionDisplay::~CurrentConditionDisplay()
{
}

void CurrentConditionDisplay::Update(int temperature, int humidity, int pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	Display();
}

void CurrentConditionDisplay::Display()
{
	cout << "¿Âµµ : ¼·¾¾ " << temperature << "µµ, ½Àµµ " << humidity << '%' << endl;
}
