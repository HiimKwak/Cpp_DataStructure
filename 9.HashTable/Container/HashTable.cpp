#include "HashTable.h"
#include <iostream>

static int GenerateHash(const std::string& keyString)
{
	int hash = 0;

	const int length = static_cast<int>(keyString.length());

	for (int ix = 0; ix < length; ++ix)
		hash = hash * 31 + keyString[ix]; // 31N=32N-N인데, 32는 25이니 어떤 수에 대한 32를 곱한 값은 shift 연산으로 쉽게 구현할 수 있다. 따라서 N에 31을 곱한 값은, (N << 5) – N과 같다. 31을 곱하는 연산은 이렇게 최적화된 머신 코드로 생성할 수 있기 때문에, String 클래스에서 해시 값을 계산할 때에는 31을 승수로 사용한다. 

	return std::abs(hash); // 오버플로우로 음수 전환 가능하기 떄문에 절대값으로 반환
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

bool HashTable::Add(const std::string& key, const std::string& value)
{
	int bucketIndex = GenerateHash(key) % bucketCount;

	std::vector<Entry>& position = table[bucketIndex];

	const int length = static_cast<int>(position.size());

	for (int ix = 0; ix < length; ++ix)
		if (position[ix].key == key) return false; // Separate 중복 키 불허
	
	position.emplace_back(Entry(key, value));
	return true;
}

bool HashTable::Delete(const std::string& key)
{
	int bucketIndex = GenerateHash(key) % bucketCount;

	std::vector<Entry>& position = table[bucketIndex];

	const int length = static_cast<int>(position.size());

	for (int ix = 0; ix < length; ++ix)
	{
		if (position[ix].key == key)
		{
			position.erase(position.begin() + ix);
			return true;
		}
	}
	return false;
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
	int bucketIndex = GenerateHash(key) % bucketCount;

	std::vector<Entry>& position = table[bucketIndex];

	if (position.size() == 0) return false;

	const int length = static_cast<int>(position.size());

	for (int ix = 0; ix < length; ++ix)
	{
		if (position[ix].key == key)
		{
			outEntry = position[ix];
			return true;
		}
	}
	
	return false;
}

void HashTable::Print()
{
	for (const auto& container : table)
	{
		if (container.size() == 0) continue;

		for (const auto& item : container)
		{
			std::cout
				<< "Key: " << item.key
				<< " | Value: " << item.value
				<< "\n";
		}
	}
}

bool HashTable::IsEmpty() const
{
	int sum = 0;
	for (const auto& container : table)
		sum += static_cast<int>(container.size());

	return sum == 0;
}
