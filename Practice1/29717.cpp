#include <iostream>
#include <cmath>

int p29717()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T;
	std::cin >> T;
	while (T--)
	{
		long long N;
		std::cin >> N;
		long long totalExp = N * (N + 1) / 2;
		long long x = std::sqrt(totalExp);
		if (x * (x + 1) > totalExp)
			--x;

		std::cout << x + 1 << "\n";
	}
	return 0;
}