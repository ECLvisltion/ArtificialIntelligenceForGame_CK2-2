#pragma once
#include "Subject.h"
#include "Observer.h"
#include <list>
#include <algorithm>
using namespace std;

class WeatherServer : public Subject
{
private:
	list<Observer *> observers; // 구독자 정보 DB
	int temperature, humidity, pressure;
	//  온도           습도        기압        구독자 수

public:
	WeatherServer();
	~WeatherServer();

	//getter
	int GetTemperature() { return temperature; }
	int GetHumidity() { return humidity; }
	int GetPressure() { return pressure; }
	//setter
	void SetMeasurement(int temperature, int humidity, int pressure); // 변경데이터 업데이트

	void RegisterObserver(Observer * obj);
	void RemoveObserver(Observer * obj);
	void NotifyObserver();
	void MeasureChanged(); // 데이터가 변경된 경우
};
