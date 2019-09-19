#include "ForecastDisplay.h"
#include <iostream>
using namespace std;

ForecastDisplay::ForecastDisplay()
{
}

ForecastDisplay::ForecastDisplay(Subject * w)
{
	wServer = w;
	wServer->RegisterObserver(this);
}

ForecastDisplay::~ForecastDisplay()
{
}

void ForecastDisplay::Update(int temperature, int humidity, int pressure)
{
	this->humidity = humidity;
	this->pressure = pressure;
	Display();
}

void ForecastDisplay::Display()
{
	// ±â¾Ðµµ Æ÷ÇÔÇÏ¿© ¼öÁ¤ ÇÊ¿ä
	if (humidity <= 50)
		cout << "³¯¾¾ : ¸¼À½" << endl;
	else
		cout << "³¯¾¾ : Èå¸²" << endl;
}
