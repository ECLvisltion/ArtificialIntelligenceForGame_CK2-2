#include "Algorithm.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Algorithm::Algorithm(int width, int height) : width(width), height(height)
{
	map = new int*[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new int[height];
	}

	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			map[i][j] = 9999;
		}
	}
}

Algorithm::~Algorithm()
{
	for (int i = 0; i < width; i++)
	{
		delete map[i];
	}
}

void Algorithm::ResetMap(int width, int height)
{
	for (int i = 0; i < width; i++)
	{
		delete map[i];
	}

	this->width = width;
	this->height = height;

	map = new int*[width];
	for (int i = 0; i < width; i++)
	{
		map[i] = new int[height];
	}
}

void Algorithm::Run()
{
	if (startX == NULL) { startX = 0; }
	if (startY == NULL) { startY = 0; }

	int hurdle = width * height / 5;
	srand((unsigned)time(NULL));
	for (int i = 0; i < hurdle; i++)
	{
		int x = rand() % width;
		int y = rand() % height;

		if (x == startX && y == startY) { i--; }
		else
		{
			map[x][y] = -1;
		}
	}

	RunElement(startX, startY, 0);
}

void Algorithm::RunElement(int x, int y, int number)
{
	if (x < 0 || x >= width) { return; }
	if (y < 0 || y >= height) { return; }
	if (map[x][y] <= number) { return; }

	map[x][y] = number;
	RunElement(x + 1, y, number + 1);
	RunElement(x - 1, y, number + 1);
	RunElement(x, y + 1, number + 1);
	RunElement(x, y - 1, number + 1);
}

void Algorithm::Show()
{
	cout << endl;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (map[i][j] == -1) { cout << "  бс "; }
			else if (map[i][j] == 9999) { cout << "  бр "; }
			else if (map[i][j] < 10) { cout << "  " << map[i][j] << "  "; }
			else if (map[i][j] < 100) { cout << "  " << map[i][j] << " "; }
			else if (map[i][j] < 1000) { cout << " " << map[i][j] << " "; }

		}
		cout << endl << endl;
	}
}
