#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#include <iostream>
#include "Container/BinarySearchTree.h"

int main()
{
#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	BinarySearchTree<int> tree;

	tree.InsertNode(20);
	tree.InsertNode(10);
	tree.InsertNode(5);
	tree.InsertNode(30);
	tree.InsertNode(25);
	tree.InsertNode(35);
	tree.InsertNode(8);

	tree.DeleteNode(30);
	tree.DeleteNode(10);
	tree.DeleteNode(8);

	tree.PreorderTraverse();
	tree.InorderTraverse();
	tree.PostorderTraverse();

	std::cin.get();
}