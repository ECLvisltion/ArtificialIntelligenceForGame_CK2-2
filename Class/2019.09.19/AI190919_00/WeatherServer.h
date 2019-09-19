#pragma once
#include "Subject.h"
#include "Observer.h"
#include <list>
#include <algorithm>
using namespace std;

class WeatherServer : public Subject
{
private:
	list<Observer *> observers; // ������ ���� DB
	int temperature, humidity, pressure;
	//  �µ�           ����        ���        ������ ��

public:
	WeatherServer();
	~WeatherServer();

	//getter
	int GetTemperature() { return temperature; }
	int GetHumidity() { return humidity; }
	int GetPressure() { return pressure; }
	//setter
	void SetMeasurement(int temperature, int humidity, int pressure); // ���浥���� ������Ʈ

	void RegisterObserver(Observer * obj);
	void RemoveObserver(Observer * obj);
	void NotifyObserver();
	void MeasureChanged(); // �����Ͱ� ����� ���
};
