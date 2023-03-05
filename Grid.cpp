#include <iostream>
#include "Grid.h"
#include "Function.h"

using namespace std;


void AddRundomNumber(Cell (&grid)[SIZE][SIZE]) {
	
	int x, y, i;

	do{
		x = randint(0, 4);
		y = randint(0, 4);

	} while(grid[x][y].num != 0);

	grid[x][y].num = 2; //randint(1,2)*2;
	
}

void ClearState(Cell(&grid)[SIZE][SIZE]) {

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++){
			grid[i][j].state = false;
		}
	}
}



Grid::Grid(int size){
		
	this->size = size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			grid[i][j].X = j;
			grid[i][j].Y = i;
			grid[i][j].state = false;
			grid[i][j].num = 0;

		}
	}
}

void Grid::Print(){
	
	system("cls");
	cout << "\n\n";

	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			cout << "\t" << grid[i][j].num;
		}
		cout << "\n\n";
	}

}

void Grid::MoveUp() {

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[k][i].num == 0) {continue;}

				if (grid[k][i].num != 0 && grid[k - 1][i].num == 0) {
					grid[k - 1][i].num = grid[k][i].num;
					grid[k][i].num = 0;
				} else if (grid[k][i].num == grid[k - 1][i].num && grid[k - 1][i].state == false && grid[k][i].state == false) {
					grid[k - 1][i].num += grid[k][i].num;
					grid[k][i].num = 0;
					grid[k - 1][i].state = true;
				} 
			}
		}
	}

	AddRundomNumber(grid);
	ClearState(grid);
}

void Grid::MoveRight() {

	for (int i = 0; i < size; i++) {
		for (int j = size-1; j>= 0; j--) {
			for (int k = j; k < size-1; k++) {

				if (grid[i][k].num == 0) {continue;}

				if (grid[i][k].num != 0 && grid[i][k + 1].num == 0) {
					grid[i][k + 1].num = grid[i][k].num;
					grid[i][k].num = 0;
				} else if (grid[i][k].num == grid[i][k + 1].num && grid[i][k + 1].state == false && grid[i][k].state == false) {
					grid[i][k + 1].num += grid[i][k].num;
					grid[i][k].num = 0;
					grid[i][k + 1].state = true;
				}
			}
		}
	}

	AddRundomNumber(grid);
	ClearState(grid);
}

void Grid::MoveDown() {

	for (int i = 0; i < size; i++) {
		for (int j = size - 1; j >= 0; j--) {
			for (int k = j; k < size - 1; k++) {

				if (grid[k][i].num == 0) {continue;}

				if (grid[k][i].num != 0 && grid[k + 1][i].num == 0) {
					grid[k + 1][i].num = grid[k][i].num;
					grid[k][i].num = 0;
				} else if (grid[k][i].num == grid[k + 1][i].num && grid[k + 1][i].state == false && grid[k][i].state == false) {
					grid[k + 1][i].num += grid[k][i].num;
					grid[k][i].num = 0;
					grid[k + 1][i].state = true;
				}
			}
		}
	}

	AddRundomNumber(grid);
	ClearState(grid);
}

void Grid::MoveLeft() {

	for (int i = 0; i < size; i++) {
		for (int j = 1; j < size; j++) {
			for (int k = j; k > 0; k--) {

				if (grid[i][k].num == 0) {continue;}

				if (grid[i][k].num != 0 && grid[i][k-1].num == 0) {
					grid[i][k - 1].num = grid[i][k].num;
					grid[i][k].num = 0;
				} else if (grid[i][k].num == grid[i][k-1].num && grid[i][k - 1].state == false && grid[i][k].state == false) {
					grid[i][k - 1].num += grid[i][k].num;
					grid[i][k].num = 0;
					grid[i][k - 1].state = true;
				}
			}
		}
	}

	AddRundomNumber(grid);
	ClearState(grid);
}





