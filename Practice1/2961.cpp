#include <iostream>
#include <cstdlib>
#include <vector>

int N;
int S, B;
int diff = 1000000000;

int p2961()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 경우의 수 = 2^n - 1
	// (1)3 - 8, (2)5 - 8, (1, 2)3*5 - 8+8

	std::cin >> N;
	std::vector<std::pair<int, int>> ingredients;
	for (int i = 0; i < N; ++i)
	{
		std::cin >> S >> B;
		ingredients.emplace_back(std::make_pair(S, B));
	}
	// 1,000,000,000보다 작은 양의 정수 = 2^31 = 부호 있는 int타입의 한계

	// ingredients 순회하면서 모든 신쓴차이 int 변수에 비트연산으로 기록, 가장 먼저 켜져있는 1 찾기
	std::vector<int> subset;
	for (int mask = 1; mask < (1 << N); mask++) // 1 << N 최대 1024번 반복, 공집합 제외
	{
		int s_product = 1;
		int b_sum = 0;

		for (int i = 0; i < N; i++)
		{
			if (mask & (1 << i)) // mask에 i번째 자리가 켜져있는지 확인
			{
				s_product *= ingredients[i].first;
				b_sum += ingredients[i].second;
			}
		}

		int subtract = std::abs(s_product - b_sum);
		diff = std::min(diff, subtract);
	}
	std::cout << diff;

	return 0;
}