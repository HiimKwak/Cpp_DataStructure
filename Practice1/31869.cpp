#include <iostream>
#define FASTIO std::cin.tie(0); std::cout.tie(0); std::ios::sync_with_stdio(false);

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Appointment {
public:
	std::string name;
	int price;
};

std::vector<std::pair<int, Appointment>> appointments;
std::unordered_map<std::string, int> prices;
bool visited[10][7];

int p31869()
{
	FASTIO

		int N;
	std::cin >> N;
	for (int i = 0; i < N; ++i)
	{
		std::string name;
		int W, D, P;
		std::cin >> name >> W >> D >> P;
		appointments.emplace_back(std::make_pair((W - 1) * 7 + D, Appointment(name, P)));
	}
	std::sort(appointments.begin(), appointments.end(), [](std::pair<int, Appointment> A, std::pair<int, Appointment> B) { return A.first < B.first; });

	for (int j = 0; j < N; ++j)
	{
		std::string name;
		int money;
		std::cin >> name >> money;
		prices.insert(std::make_pair(name, money));
	}

	for (int i = 0; i < N; ++i)
	{
		int week = appointments[i].first / 7, day = appointments[i].first % 7;
		std::string name = appointments[i].second.name;
		int price = appointments[i].second.price;
		if (prices[name] >= price)
		{
			visited[week][day] = true;
			prices[name] = -1;
		}
	}

	int sequence = 0;
	int answer = 0;
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 7; ++j)
		{
			if (visited[i][j])
				sequence++;
			else
			{
				answer = std::max(answer, sequence);
				sequence = 0;
			}
		}
	}
	answer = std::max(answer, sequence);

	std::cout << answer;

	return 0;
}