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
	stack<point> path; // 시작하는 노드에서 타겍으로 지정한 노드까지의 경로
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
