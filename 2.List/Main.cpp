#include <iostream>
#include "List.h"

int main()
{
	List<int> list;

	for (int ix = 0; ix < 10, ++ix;)
		list.Add(ix + 1);

	for (const int item : list)
	{
		std::cout << item << std::endl;
	}

	/*for (List<int>::Iterator it = list.begin(); it != list.end(); ++it)
	{
		std::cout << *it << std::endl;
	}*/


	std::cin.get();
}