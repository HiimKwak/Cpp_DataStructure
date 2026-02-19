#include <iostream>
#include <Windows.h>
#include "Container/Stack.h"
#include "Location2D.h"

//const int mazeSize = 6;
//char map[mazeSize][mazeSize] =
//{
//	{'1','1','1','1','1','1'},
//	{'e','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','x'},
//	{'1','1','1','1','1','1'}
//};

const int mazeSize = 20;
char map[mazeSize][mazeSize] =
{
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
	{'e', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
	{'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
	{'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
	{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'x'},
	{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

bool IsValidLocation(const Location2D& location)
{
	const int row = location.row;
	const int col = location.col;

	if (row < 0 || row >= mazeSize || col < 0 || col >= mazeSize) return false;

	return map[row][col] == '0' || map[row][col] == 'x';
}

void ClearScreen()
{
	system("cls");
}

void SetConsoleColor(WORD color)
{
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		color
	);
}

void PrintMap(const Location2D& playerPosition, DWORD delay)
{
	Sleep(delay);

	//ClearScreen();
	COORD coord;
	coord.X = 0;
	coord.Y = 0;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);

	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			if (row == playerPosition.row && col == playerPosition.col)
			{
				SetConsoleColor(FOREGROUND_GREEN);
				std::cout << "P ";
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				continue;
			}
			if (map[row][col] == 'x')
			{
				SetConsoleColor(FOREGROUND_RED);
				std::cout << "X ";
				SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				continue;
			}
			std::cout << map[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	Location2D start;

	bool found = false;
	for (int row = 0; row < mazeSize; ++row)
	{
		for (int col = 0; col < mazeSize; ++col)
		{
			if (map[row][col] == 'e')
			{
				start.row = row;
				start.col = col;
				found = true;
				break;
			}
		}
		if (found) break;
	}

	PrintMap(start, 0);

	Stack<Location2D, mazeSize> stack;
	stack.Push(start);
	while (!stack.IsEmpty())
	{
		Location2D current;
		stack.Pop(current);

		PrintMap(current, 500);

		if (map[current.row][current.col] == 'x')
		{
			std::cout << "\n미로 탐색 성공\n";
			return 0;
		}

		map[current.row][current.col] = '.';
		if (IsValidLocation(Location2D(current.row - 1, current.col)))
			stack.Push(Location2D(current.row - 1, current.col));
		if (IsValidLocation(Location2D(current.row + 1, current.col)))
			stack.Push(Location2D(current.row + 1, current.col));
		if (IsValidLocation(Location2D(current.row, current.col - 1)))
			stack.Push(Location2D(current.row, current.col - 1));
		if (IsValidLocation(Location2D(current.row, current.col + 1)))
			stack.Push(Location2D(current.row, current.col + 1));
	}
	std::cout << "미로 탐색 실패\n";
}