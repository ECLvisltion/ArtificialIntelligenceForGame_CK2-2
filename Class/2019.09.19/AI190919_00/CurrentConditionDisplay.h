#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"

class CurrentConditionDisplay : public Observer, public DisplayElement
{
private:
	int temperature, humidity;
	Subject * wServer;

public:
	CurrentConditionDisplay();
	CurrentConditionDisplay(Subject * w);
	~CurrentConditionDisplay();

	void Update(int temperature, int humidity, int pressure);
	void Display();
};
