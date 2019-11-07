#include "GameMap.h"
#include <cassert>
#include <memory>
#include <iostream>
using namespace std;

GameMap::GameMap()
{
	map = new int*[mapHeight];
	visitInfo = new bool*[mapHeight];
	for (int i = 0; i < mapHeight; i++)
	{
		map[i] = new int[mapWidth];
		visitInfo[i] = new bool[mapWidth];
	}
	assert(map != nullptr && visitInfo != nullptr);
}

GameMap::~GameMap()
{
	assert(map != nullptr);
	for (int i = 0; i < mapHeight; i++) { delete[] map[i]; }
	delete[] map;

	assert(visitInfo != nullptr);
	for (int i = 0; i < mapHeight; i++) { delete[] visitInfo[i]; }
	delete[] visitInfo;
}

void GameMap::SetMap(int ** map)
{
	memcpy(this->map, map, sizeof(int) * mapWidth * mapHeight);
}

void GameMap::InitMap()
{
	assert(map != nullptr && visitInfo != nullptr);
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapHeight; x++)
		{
			map[y][x] = 9999;
			visitInfo[y][x] = false;
		}
	}
}

void GameMap::Draw()
{
	assert(map != nullptr);
	for (int y = 0; y < mapHeight; y++)
	{
		for (int x = 0; x < mapWidth; x++)
		{
			cout << map[y][x] << "\t";
		}
		cout << endl;
	}
}
