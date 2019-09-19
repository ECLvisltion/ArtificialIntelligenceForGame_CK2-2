#include "CurrentConditionDisplay.h"
#include "ForecastDisplay.h"
#include "StatisticDisplay.h"
#include "WeatherServer.h"
#include <iostream>
using namespace std;

int main()
{
	WeatherServer * weather = new WeatherServer();
	CurrentConditionDisplay * ccd = new CurrentConditionDisplay(weather);
	ForecastDisplay * fd = new ForecastDisplay(weather);
	StatisticDisplay * sd = new StatisticDisplay(weather);


	weather->SetMeasurement(25, 40, 30);
	cout << "------------------------------" << endl;
	weather->SetMeasurement(30, 20, 25);
	cout << "------------------------------" << endl;
	weather->SetMeasurement(20, 50, 40);
	cout << "------------------------------" << endl;
	weather->SetMeasurement(17, 70, 20);
	cout << "------------------------------" << endl;
	weather->SetMeasurement(35, 0, 80);
	cout << "------------------------------" << endl;

	delete weather, ccd, fd, sd;
	return 0;
}