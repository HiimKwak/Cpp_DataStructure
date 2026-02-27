#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct User
{
	int id;
	int age;
	std::string name;

	User(int id, int age, const std::string& name)
		: id(id), age(age), name(name) {
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<User> userList;
	userList.reserve(n);  // 재할당 방지 (성능 최적화)

	for (int i = 0; i < n; ++i)
	{
		int age;
		std::string name;
		std::cin >> age >> name;

		userList.emplace_back(i, age, name);
	}

	std::stable_sort(userList.begin(), userList.end(),
		[](const User& a, const User& b)
		{
			return a.age < b.age;
		});

	for (const auto& user : userList)
	{
		std::cout << user.age << " " << user.name << "\n";
	}

	return 0;
}