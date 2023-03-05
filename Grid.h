#pragma once

typedef struct Cell {
	int X, Y;
	int num;
	bool state;
};

class Grid {
	int size;
	Cell grid[4][4];

public:

	Grid(int size);

	void Print();
	void MoveUp();
	void MoveRight();
	void MoveDown();
	void MoveLeft();

};