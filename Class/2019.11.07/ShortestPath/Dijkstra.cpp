#include "Dijkstra.h"
#include "GameMap.h"

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}

point Dijkstra::Choose()
{
	int min = INT_MAX;
	int width = GameMap::mapWidth;
	int height = GameMap::mapHeight;
	int cx, cy;
	point choicePos;
	list<point>::reverse_iterator curPos;

	for (curPos = visitNode.rbegin(); curPos != visitNode.rend(); curPos++)
	{
		for (int ty = -1; ty <= 1; ty++)
		{
			for (int tx = -1; tx <= 1; tx++)
			{
				cx = curPos->x + tx;
				cy = curPos->y + ty;

				if (cx < 0 || cx > width - 1 || cy < 0 || cy > height - 1)
					continue;

				if (gameMap->GetMapValue(cx, cy) < min && gameMap->GetVisitInfo(cx, cy) == false)
				{
					min = gameMap->GetMapValue(cx, cy);
					choicePos = { cx, cy };
				}
			}
		}
	}

	return choicePos;
}

//sx, sy 시작 좌표
//tx, ty = 타겍 좌표
bool Dijkstra::FindPath(int sx, int sy, int tx, int ty)
{
	bFound = false;

	int width = GameMap::mapWidth;
	int height = GameMap::mapHeight;

	point **parent;
	parent = new point*[height];
	for (int i = 0; i < height; i++) { parent[i] = new point[width]; }

	point choicePos;
	gameMap->SetMapValue(sx, sy, 0); // 시작 노드의 비용 초기화
	choicePos = { sx, sy };
	parent[sy][sx] = choicePos;
	visitNode.push_back(choicePos);

	for (int i = 0; i < height * width; i++)
	{
		choicePos = Choose();
		gameMap->SetVisitInfo(choicePos.x, choicePos.y, true); // 방문 정보 갱신
		visitNode.push_back(choicePos); // 방문 노드 리스트에 현재 노드 추가

		if (choicePos.x == tx && choicePos.y == ty) // 타겟 노드를 찾으면 리턴
		{
			bFound = true;
			break;
		}

		// 현재 노드를 기준으로 8방형을 엣지 완화
		for (int oy = -1; oy <= 1; oy++)
		{
			for (int ox = -1; ox <= 1; ox++)
			{
				int nextX = choicePos.x + ox;
				int nextY = choicePos.y + oy;
				int dist; // 한 칸 이동하는데 드는 비용

				if (nextX < 0 || nextX > width - 1 || nextY < 0 || nextY > height - 1) // 맵을 벗어난 경우
				{
					continue;
				}
				if (gameMap->GetVisitInfo(nextX, nextY) == false)
				{
					dist = (ox == 0 || oy == 0) ? 10 : 14;
					// 엣지 완화
					int sToNext = gameMap->GetMapValue(nextX, nextY);
					int sToCur = gameMap->GetMapValue(choicePos.x, choicePos.y);
					if (sToCur + dist < sToNext)
					{
						gameMap->SetMapValue(nextX, nextY, sToCur + dist);
						parent[nextY][nextX] = choicePos;
					}
				}
			}
		}
	}

	if (bFound == true)
	{
		point p;
		p = { tx, ty };
		path.push(p);
		while (p.x != sx || p.y != sy)
		{
			p = parent[p.y][p.x];
			path.push(p);
		}
	}

	return bFound;
}

void Dijkstra::Draw()
{
	gameMap->Draw();

	if (bFound)
	{
		point curPoint;
		do
		{
			curPoint = path.top();
			cout << '(' << curPoint.x << ", " << curPoint.y << ") -> ";
			path.pop();
		} while (!path.empty());
		cout << endl << "가장 짧은 거리" << endl;
	}
}
