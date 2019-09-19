#include "StatisticDisplay.h"
#include <iostream>
using namespace std;

StatisticDisplay::StatisticDisplay() : minTemp(NULL), maxTemp(NULL), totalTemp(NULL), countTemp(0)
{
}

StatisticDisplay::StatisticDisplay(Subject * w) : minTemp(NULL), maxTemp(NULL), totalTemp(NULL), countTemp(0)
{
	wServer = w;
	wServer->RegisterObserver(this);
}

StatisticDisplay::~StatisticDisplay()
{
}

void StatisticDisplay::Update(int temperature, int humidity, int pressure)
{
	countTemp++;
	totalTemp += temperature;
	if (minTemp == NULL || minTemp > temperature) { minTemp = temperature; }
	if (maxTemp == NULL || maxTemp < temperature) { maxTemp = temperature; }
	Display();
}

void StatisticDisplay::Display()
{
	cout << "Æò±Õ ¿Âµµ : ¼·¾¾ " << (float)totalTemp / countTemp << "µµ, ÃÖ°í ¿Âµµ : ¼·¾¾ " << maxTemp << "µµ, ÃÖÀú ¿Âµµ : ¼·¾¾ " << minTemp << "µµ" << endl;
}
