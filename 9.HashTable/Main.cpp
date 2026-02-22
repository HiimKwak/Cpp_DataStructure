#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Container/HashTable.h"

int main()
{
	HashTable table;

	table.Add("A", "01029484572");
	table.Add("B", "01029484572");
	table.Add("C", "01029484572");
	table.Add("D", "01029484572");
	table.Add("E", "01029484572");

	table.Print();

	Pair<std::string, std::string> outValue;
	if (table.Find("B", outValue))
	{
		std::cout
			<< "검색 성공. Key: " << outValue.key
			<< " | Value: " << outValue.value << "\n";
	}

	table.Delete("E");
	table.Delete("D");

	table.Print();

	std::cin.get();
}