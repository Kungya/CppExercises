#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoxy(int x, int y);
char GetKeyBoard(void);

int main()
{
	char input = '\0';
	int x = 1, y = 1;


	while (1) {
		gotoxy(x, y);
		cout << "★";

		input = GetKeyBoard();

		switch (input)
		{
		case 'w':   // ↑
			y--;
			break;
		case 'a':   // ←
			x--;
			break;
		case 's':   // ↓
			y++;
			break;
		case 'd':   // →
			x++;
			break;
		}
		Sleep(10);
		system("cls");
	}

	return 0;
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

char GetKeyBoard(void) {
	if (_kbhit()) {
		return _getch();
	}

	return '\0';
}