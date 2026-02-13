#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "LinkedList/LinkedList.h"
#include <stdlib.h>
#include <crtdbg.h>
#include <list>
#include <forward_list>

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::forward_list<int> stlList;
	stlList.emplace_after(stlList.begin(), 10);

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