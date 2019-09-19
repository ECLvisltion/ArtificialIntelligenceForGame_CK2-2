#pragma once

class Observer
{
public:
	virtual void Update(int temperature, int humidity, int pressure) = 0;
};
