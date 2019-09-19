#pragma once

class Observer;
class Subject
{
public:
	virtual void RegisterObserver(Observer *) = 0;
	virtual void RemoveObserver(Observer *) = 0;
	virtual void NotifyObserver() = 0;
};
