
#include <iostream>
#include <Windows.h>
#include "Function.h"
#include "Grid.h"

using namespace std;

int main(){

	srand(9/*time(nullptr)*/);

	Grid grid(SIZE);
	
	system("mode con cols=41 lines=13");
	SetConsoleOption();
	
	int g = 0;

	grid.Print();

	while (true){
		
	
		if (GetAsyncKeyState(65) && g != 1) {
			grid.MoveLeft(); g = 1;
			grid.Print();
		} else if (GetAsyncKeyState(83) && g != 1) {
			grid.MoveDown(); g = 1;
			grid.Print();
		} else if (GetAsyncKeyState(68) && g != 1) {
			grid.MoveRight(); g = 1;
			grid.Print();
		} else if (GetAsyncKeyState(87) && g != 1) {
			grid.MoveUp();
			grid.Print();
		} 

		if(!GetAsyncKeyState(65) && 
		   !GetAsyncKeyState(83) && 
		   !GetAsyncKeyState(68) && 
		   !GetAsyncKeyState(87)) {
			g = 0;
		}

		Sleep(100);

	}
}
