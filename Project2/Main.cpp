#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Container/HashTable.h"
#include "UI/UI.h"

int main()
{
	HashTable itemDict;

	if (itemDict.LoadFromFile("data.txt"))
	{
		std::cout << "data.txt에서 아이템 데이터를 로드했습니다.\n";
	}
	else
	{
		std::cout << "data.txt 파일을 찾을 수 없습니다.\n";
	}

	std::cout << "UI 모드로 시작합니다... (3초 후)\n";
	Sleep(3000);

	int selected = 0;
	while (true)
	{
		std::vector<Item> items = itemDict.GetAllItems();

		if (items.empty())
		{
			std::cout << "아이템이 없습니다. 명령어 모드로 전환합니다.\n";
			Sleep(2000);
			CommandMode(itemDict);
			continue;
		}

		RenderUI(items, selected, (selected - 2 + (int)items.size()) % (int)items.size());

		int ch = _getch();
		if (ch == 0xE0)
		{
			ch = _getch();
			if (ch == 72) // 위쪽 화살표
				selected = (selected - 1 + items.size()) % items.size();
			if (ch == 80) // 아래쪽 화살표
				selected = (selected + 1) % items.size();
		}
		if (ch == 27 || ch == 113) // ESC 또는 'q'
		{
			CommandMode(itemDict);
			selected = 0; // 명령어 모드 후 선택 초기화
		}
	}

	return 0;
}