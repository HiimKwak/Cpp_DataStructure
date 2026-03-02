#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Container/Vector.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Vector<int> v;
	v.Add(1);
	v.Add(2);
	v.Add(3);
	v.Add(4);
	v.Add(5);
	v.Add(6);
}