#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"

class StatisticDisplay : public Observer, public DisplayElement
{
private:
	int minTemp, maxTemp, totalTemp, countTemp;
	Subject * wServer;

public:
	StatisticDisplay();
	StatisticDisplay(Subject * w);
	~StatisticDisplay();

	void Update(int temperature, int humidity, int pressure);
	void Display();
};
