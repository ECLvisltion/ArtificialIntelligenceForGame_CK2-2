#pragma once
#include "Init.h"
#include <stack>
#include <list>
#include <iostream>
using namespace std;

class GameMap;

class Dijkstra
{
private:
	GameMap *gameMap;
	stack<point> path; // �����ϴ� ��忡�� Ÿ������ ������ �������� ���
	list<point> visitNode;
	bool bFound;

public:
	Dijkstra();
	Dijkstra(GameMap* map) : gameMap(map), bFound(false) {};
	~Dijkstra();

	point Choose();
	bool FindPath(int sx, int sy, int tx, int ty);
	void Draw();
};
