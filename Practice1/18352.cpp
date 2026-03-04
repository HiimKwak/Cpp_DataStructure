#include <iostream>
#include <vector>

struct City
{
	int id;
	std::vector<int> subcities;
};

void BFS(std::vector<City> cities)
{

}

int p18352()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m, k, x;
	std::cin >> n >> m >> k >> x;

	std::vector<City> cities;

	for (int i = 0; i < n; ++i)
	{
		cities.emplace_back(i, std::vector<int>());
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		std::cin >> a >> b;
		cities[a - 1].subcities.emplace_back(b - 1);
	}

	for (City city : cities)
	{
		if (city.id == x - 1)
		{
			while (k > 0)
			{
				BFS(cities);
				--k;
			}
		}
	}

	return 0;
}