#include "Astar.h"
#include "GameMap.h"

Astar::Astar()
{
}

Astar::~Astar()
{
}

point Astar::Choose(int dx, int dy) // dx, dy : ������ ���
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

				// �޸���ƽ�� ���
				// hx, y : ���� ��忡�� ������������ �Ÿ�
				int hx = abs(cx - dx) * 10;
				int hy = abs(cy - dy) * 10;
				int hdist = hx + hy;

				if (gameMap->GetMapValue(cx, cy) + hdist < min && gameMap->GetVisitInfo(cx, cy) == false)
				{
					min = gameMap->GetMapValue(cx, cy) + hdist;
					choicePos = { cx, cy };
				}
			}
		}
	}

	return choicePos;
}

bool Astar::FindPath(int sx, int sy, int tx, int ty)
{
	bFound = false;

	int width = GameMap::mapWidth;
	int height = GameMap::mapHeight;

	point **parent;
	parent = new point*[height];
	for (int i = 0; i < height; i++) { parent[i] = new point[width]; }

	point choicePos;
	gameMap->SetMapValue(sx, sy, 0); // ���� ����� ��� �ʱ�ȭ
	choicePos = { sx, sy };
	parent[sy][sx] = choicePos;
	visitNode.push_back(choicePos);

	for (int i = 0; i < height * width; i++)
	{
		choicePos = Choose(tx, ty);
		gameMap->SetVisitInfo(choicePos.x, choicePos.y, true); // �湮 ���� ����
		visitNode.push_back(choicePos); // �湮 ��� ����Ʈ�� ���� ��� �߰�

		if (choicePos.x == tx && choicePos.y == ty) // Ÿ�� ��带 ã���� ����
		{
			bFound = true;
			break;
		}

		// ���� ��带 �������� 8������ ���� ��ȭ
		for (int oy = -1; oy <= 1; oy++)
		{
			for (int ox = -1; ox <= 1; ox++)
			{
				int nextX = choicePos.x + ox;
				int nextY = choicePos.y + oy;
				int dist; // �� ĭ �̵��ϴµ� ��� ���

				if (nextX < 0 || nextX > width - 1 || nextY < 0 || nextY > height - 1) // ���� ��� ���
				{
					continue;
				}
				if (gameMap->GetVisitInfo(nextX, nextY) == false)
				{
					dist = (ox == 0 || oy == 0) ? 10 : 14;
					// ���� ��ȭ
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

void Astar::Draw()
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
		cout << endl << "���� ª�� �Ÿ�" << endl;
	}
}
