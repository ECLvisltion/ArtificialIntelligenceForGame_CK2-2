#pragma once

class GameMap
{
public:
	static int mapWidth;
	static int mapHeight;
private:
	int **map;
	bool **visitInfo;

public:
	GameMap();
	~GameMap();

	// Setter
	void SetMap(int **map);
	void SetMapValue(int x, int y, int value) { map[y][x] = value; }
	void SetVisitInfo(int x, int y, bool isVisit) { visitInfo[y][x] = isVisit; }
	// Getter
	int GetMapValue(int x, int y) { return map[y][x]; }
	bool GetVisitInfo(int x, int y) { return visitInfo[y][x]; }

	void InitMap();
	void Draw();
};
