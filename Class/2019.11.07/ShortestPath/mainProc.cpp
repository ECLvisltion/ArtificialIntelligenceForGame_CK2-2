#include "Dijkstra.h"
#include "GameMap.h"
#include "Astar.h"

int GameMap::mapHeight = 10;
int GameMap::mapWidth = 10;

int main()
{
	GameMap* gameMap = new GameMap();
	Dijkstra* dijkstra = new Dijkstra(gameMap);
	Astar* astar = new Astar(gameMap);

	gameMap->InitMap();
	gameMap->Draw();
	dijkstra->FindPath(0, 9, 9, 0);
	dijkstra->Draw();
	gameMap->InitMap();
	astar->FindPath(0, 9, 9, 0);
	astar->Draw();


	return 0;
}