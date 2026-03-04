#include "UI.h"
#include "../Common/Utils.h"
#include <iostream>
#include <sstream>
#include <string>

void RenderUI(const std::vector<Item>& items, int selected, int offset)
{
	system("cls");

	Util::PutCursorOnPosition(0, 0);
	Util::ColorText(Util::Color::LIGHTCYAN);
	std::cout << "=== 아이템 사전 (HashTable) ===\n";
	Util::ColorText(Util::Color::LIGHTGRAY);
	std::cout << "[방향키: 이동] [ESC/Q: 명령어 모드]";

	int displayCount = 20;
	for (int i = 0; i < displayCount && i < (int)items.size(); ++i)
	{
		int idx = (offset + i) % items.size();
		Util::PutCursorOnPosition(0, i + 3);

		if (idx == selected)
		{
			Util::ColorText(Util::Color::YELLOW);
			std::cout << "> ";
		}
		else
		{
			Util::ColorText(Util::Color::WHITE);
			std::cout << "  ";
		}
		std::cout << items[idx].name << " (" << items[idx].type << ")";
	}

	// 우측 상세 정보
	if (!items.empty())
	{
		const Item& item = items[selected];
		Util::PutCursorOnPosition(40, 3);
		Util::ColorText(Util::Color::LIGHTGREEN);
		std::cout << "[ 아이템 상세 정보 ]";

		Util::PutCursorOnPosition(40, 5);
		Util::ColorText(Util::Color::WHITE);
		std::cout << "Name   : ";
		Util::ColorText(Util::Color::YELLOW);
		std::cout << item.name;

		Util::PutCursorOnPosition(40, 6);
		Util::ColorText(Util::Color::WHITE);
		std::cout << "Type   : ";
		Util::ColorText(Util::Color::LIGHTCYAN);
		std::cout << item.type;

		Util::PutCursorOnPosition(40, 7);
		Util::ColorText(Util::Color::WHITE);
		std::cout << "Value  : ";
		Util::ColorText(Util::Color::LIGHTMAGENTA);
		std::cout << item.value;
	}

	Util::ColorText(Util::Color::WHITE);
}

void CommandMode(HashTable& itemDict)
{
	system("cls");
	std::cout << "=== 명령어 모드 ===" << "\n";
	std::cout << "명령어: add [name] [type] [value]" << "\n";
	std::cout << "        find [name]" << "\n";
	std::cout << "        remove [name]" << "\n";
	std::cout << "        list" << "\n";
	std::cout << "        ui (UI 모드로 전환)" << "\n";
	std::cout << "        exit" << "\n";
	std::cout << "====================" << "\n" << "\n";

	std::string line;
	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, line);

		std::stringstream ss(line);
		std::string command;
		ss >> command;

		if (command == "add")
		{
			std::string name, type;
			int value;
			if (ss >> name >> type >> value)
			{
				itemDict.Add(name, type, value);
				std::cout << "아이템 추가: " << name << "\n";
			}
			else
			{
				std::cout << "사용법: add [name] [type] [value]" << "\n";
			}
		}
		else if (command == "find")
		{
			std::string name;
			ss >> name;
			Item* item = itemDict.Find(name);
			if (item)
			{
				std::cout << "Name: " << item->name
					<< ", Type: " << item->type
					<< ", Value: " << item->value << "\n";
			}
			else
			{
				std::cout << "아이템을 찾을 수 없습니다: " << name << "\n";
			}
		}
		else if (command == "remove")
		{
			std::string name;
			ss >> name;
			if (itemDict.Remove(name))
			{
				std::cout << "아이템 삭제: " << name << "\n";
			}
			else
			{
				std::cout << "아이템을 찾을 수 없습니다: " << name << "\n";
			}
		}
		else if (command == "list")
		{
			std::cout << "\n=== 전체 아이템 목록 ===" << "\n";
			itemDict.List();
			std::cout << "=====================\n" << "\n";
		}
		else if (command == "ui")
		{
			return; // UI 모드로 복귀
		}
		else if (command == "exit")
		{
			exit(0);
		}
		else
		{
			std::cout << "알 수 없는 명령어입니다." << "\n";
		}
	}
}
