#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

#include "Container/Tree.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Tree<int> tree(10);
	tree.AddChild(10, 9);
	tree.AddChild(10, 8);
	tree.AddChild(9, 7);
	tree.AddChild(9, 6);

	Node<int>* outNode = nullptr;
	if (tree.Find(6, outNode))
		int number2 = 30;

	tree.PreorderTraversal();

	if (tree.Remove(9))
		int number3 = 30;


	int number = 10;
}