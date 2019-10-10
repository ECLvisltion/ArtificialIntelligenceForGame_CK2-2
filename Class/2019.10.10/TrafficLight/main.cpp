#include "TrafficLight.h"
#include <Windows.h>

int main()
{
	TrafficLight trafficLight;
	
	for (int i = 0; i < 30; i++)
	{
		trafficLight.Update();
		Sleep(1000);
	}

	return 0;
}
