#include <iostream>
#include <string>
#include <sstream>
#include "Container/HashTable.h"

int main()
{
	HashTable itemDict;

	// CSV 파일에서 아이템 로드
	if (itemDict.LoadFromFile("data.txt"))
	{
		std::cout << "data.txt에서 아이템 데이터를 로드했습니다.\n" << "\n";
	}
	else
	{
		std::cout << "data.txt 파일을 찾을 수 없습니다. 수동으로 아이템을 추가하세요.\n" << "\n";
	}

	std::cout << "=== 아이템 사전 (HashTable) ===" << "\n";
	std::cout << "명령어: add [name] [type] [value]" << "\n";
	std::cout << "        find [name]" << "\n";
	std::cout << "        remove [name]" << "\n";
	std::cout << "        list" << "\n";
	std::cout << "        exit" << "\n";
	std::cout << "================================" << "\n" << "\n";

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
				std::cout << "아이템 추가: " << name << std::endl;
			}
			else
			{
				std::cout << "사용법: add [name] [type] [value]" << std::endl;
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
		else if (command == "exit")
		{
			break;
		}
		else
		{
			std::cout << "알 수 없는 명령어입니다." << "\n";
		}
	}

	return 0;
}