#pragma once
#include "Init.h"
#include <stack>
#include <list>
#include <iostream>
using namespace std;

class GameMap;

class Astar
{
private:
	GameMap *gameMap;
	stack<point> path; // �����ϴ� ��忡�� Ÿ������ ������ �������� ���
	list<point> visitNode;
	bool bFound;

public:
	Astar();
	Astar(GameMap* map) : gameMap(map), bFound(false) {};
	~Astar();

	point Choose(int dx, int dy);
	bool FindPath(int sx, int sy, int tx, int ty);
	void Draw();
};
