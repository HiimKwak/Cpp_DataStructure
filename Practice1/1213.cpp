#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::string name;
std::map<char, int> alphabet;

int p1213()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> name;

	// 문자열 한바퀴 돌면서 문자별로 개수 세기
	// 홀수개인 문자열이 0개 또는 1개 있어야 펠린드롬, 2개 이상이면 실패
	// 사전순으로 정렬된 펠린드롬 출력하기 = 아스키코드(int)
	for (size_t i = 0; i < name.length(); i++)
	{
		auto remainder = alphabet.find(name[i]);
		if (remainder != alphabet.end()) // iter에서 못찾으면 end 반환
			remainder->second++;
		else alphabet.insert(std::make_pair(name[i], 1));
	}

	int oddCount = 0;
	char oddChar = '\0';
	for (auto it = alphabet.begin(); it != alphabet.end(); it++)
	{
		if (it->second % 2 == 1)
		{
			oddCount++;
			oddChar = it->first;
		}
	}
	if (oddCount > 1)
	{
		std::cout << "I'm Sorry Hansoo";
		return 0;
	}

	std::string front;
	for (auto it = alphabet.begin(); it != alphabet.end(); it++)
	{
		if (it->first == oddChar)
			it->second--;

		for (int i = 0; i < it->second / 2; ++i)
			front.push_back(it->first);
	}
	std::string back(front.rbegin(), front.rend());
	std::string pelindrom = (oddCount == 1)
		? front + oddChar + back
		: front + back;

	std::cout << pelindrom;
	return 0;
}