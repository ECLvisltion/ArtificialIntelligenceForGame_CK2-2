#include "WeatherServer.h"

WeatherServer::WeatherServer()
{
}

WeatherServer::~WeatherServer()
{
}

void WeatherServer::SetMeasurement(int temperature, int humidity, int pressure)
{
	this->temperature = temperature;
	this->humidity = humidity;
	this->pressure = pressure;
	MeasureChanged();
}

void WeatherServer::RegisterObserver(Observer * obj)
{
	observers.push_back(obj);
}

void WeatherServer::RemoveObserver(Observer * obj)
{
	observers.remove(obj);
}

void WeatherServer::NotifyObserver()
{
	list<Observer *>::iterator iterPos;

	for (iterPos = observers.begin(); iterPos != observers.end(); iterPos++)
	{
		Observer * curObj = *iterPos;
		curObj->Update(temperature, humidity, pressure);
	}
}

void WeatherServer::MeasureChanged()
{
	NotifyObserver();
}
