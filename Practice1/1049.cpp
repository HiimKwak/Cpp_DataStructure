#include <iostream>
#include <algorithm>

int p1049()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N = 0, M = 0;
	std::cin >> N >> M;
	//std::priority_queue<int, int, std::greater<int>> package;
	//std::priority_queue<int, int, std::greater<int>> single;
	int pmin = 1000, smin = 1000;

	for (int i = 0; i < M; ++i)
	{
		int p, s;
		std::cin >> p >> s;
		//package.push(f);
		//single.push(s);
		pmin = std::min(pmin, p);
		smin = std::min(smin, s);
	}

	//int min = 0;
	//for (int i = 0; i < M; ++i)
	//{
	//	int p = package.top();
	//	int s = single.top();
	//}
	int base = pmin * (N / 6);
	int temp = std::min((N % 6 == 0) ? base : base + pmin, base + (N % 6) * smin);

	std::cout << std::min(smin * N, temp);

	return 0;
}