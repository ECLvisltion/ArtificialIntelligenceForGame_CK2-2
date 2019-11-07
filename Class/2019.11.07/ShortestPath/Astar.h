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
	stack<point> path; // 시작하는 노드에서 타겍으로 지정한 노드까지의 경로
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
