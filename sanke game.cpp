#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <vector>
#include <cmath>
using namespace std;

bool game_over;
const int latime = 40;
const int lungime = 20;
int ltail;
vector<int> tailX(100,0);
vector<int> tailY(100,0);
int x, y, fruitX, fruitY, score;
enum directie { stop = 0, stanga, dreapta, sus, jos };
directie dir;

void game() {
	 game_over = false;
	 dir = stop;
	 x = latime / 2;
	 y = lungime / 2;
	 fruitX = (rand() % latime-1);
	 if (fruitX == 0)
		 fruitX++;
	 fruitY = (rand() % lungime-1);
	 if (fruitY == 0)
		 fruitY++;
	 score = 0;
}

void print() {
	system("cls");
	//top
	for (int i = 0; i < latime; i++) {
		if (i == 0)
			cout << '#';
		else
			if (i == latime - 1)
				cout << '#';
			else
				cout << '#';
	}
		

	cout << endl;

	//mid
	for (int j = 0; j < lungime; j++)
	for (int i = 0; i < latime; i++) {

			if (i == 0)
				cout << '#';
			else
			if (i == latime - 1)
				cout << '#' << endl;
			else
			if (j == y and i == x)//head
					cout << (char)254;
				else
					if (i == fruitX and j == fruitY)
						cout << (char)14;//fruit
					else
					{
						bool ok = false;
						for (int k = 0; k < ltail; k++) {
							
							if (tailX[k] == i and tailY[k] == j) {
								cout << 'o';
								ok = true;
							}
								
						}
						if (!ok)
							cout << ' ';
					}
			
				
	}

	
	//botom
	for (int i = 0; i < latime; i++) {
		if (i == 0)
			cout << '#';
		else
			if (i == latime - 1)
				cout << '#' << endl;
			else
				cout << '#';
	}
		
	cout << endl;
	cout << "Score: " << score;
}

void input() {
	if (_kbhit()) {

		switch (_getch()) {

		case 'a':
			dir = stanga;
			break;
		case 'd':
			dir = dreapta;
			break;
		case 's':
			dir = jos;
			break;
		case 'w':
			dir = sus;
			break;
		case 'x':
			game_over = true;
			break;
		}

	}

}

void logic() {

	int prevX = tailX[0];//0
	int prevY = tailY[0];//0
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;

	for (int i = 1; i < ltail; i++) {

		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;

	}
	
	switch (dir)
	{
	case stanga:
		x--;
		break;
	case dreapta:
		x++;
		break;
	case sus:
		y--;
		break;
	case jos:
		y++;
		break;

	default:
		break;
	}
	if (x >= latime-1 or x<=0 or y >= lungime or y<0)
		game_over = true;

	if (x == fruitX and y == fruitY) {
		score++;
		fruitX = (rand() % latime-1) ;
		fruitY = (rand() % lungime-1);
		 if (fruitX == 0)
		 fruitX++;
		if (fruitY == 0)
		 fruitY++;
		ltail++;

	}

	for (int i = 0; i < ltail; i++)
		if (tailX[i] == x and tailY[i] == y)
			game_over = true;

}

int main(){
	srand(time(NULL));
	game();
	while (!game_over) {
		print();
		input();
		logic();
		Sleep(abs(15-score));
	}

	return 0;
}
