#pragma once
class Algorithm
{
private:
	int** map;
	int width, height;
	int startX, startY;

public:
	Algorithm(int width, int height);
	~Algorithm();

	// setter
	void SetStart(int x, int y) { startX = y; startY = x; }
	void ResetMap(int width, int height);

	void Run();
	void RunElement(int x, int y, int number);
	void Show();
};
