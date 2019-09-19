#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"

class ForecastDisplay : public Observer, DisplayElement
{
private:
	int humidity, pressure;
	Subject * wServer;

public:
	ForecastDisplay();
	ForecastDisplay(Subject * w);
	~ForecastDisplay();

	void Update(int temperature, int humidity, int pressure);
	void Display();
};
