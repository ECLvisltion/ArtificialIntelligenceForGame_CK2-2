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
	// ��е� �����Ͽ� ���� �ʿ�
	if (humidity <= 50)
		cout << "���� : ����" << endl;
	else
		cout << "���� : �帲" << endl;
}
