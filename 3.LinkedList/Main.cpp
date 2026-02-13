#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "LinkedList/LinkedList.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	LinkedList<int> list;
	list.Insert(20);
	list.Insert(30);
	list.Insert(10);

	list.Print();

	list.Delete(30);
	list.Delete(10);

	list.Print();

	std::cin.get();
}