#pragma once

#include "Pair.h"
#include <vector>
#include <string>

class HashTable
{
private:
	using Entry = Pair<std::string, std::string>;

public:
	HashTable();
	~HashTable();

	bool Add(const std::string& key, const std::string& value);
	bool Delete(const std::string& key);
	bool Find(const std::string& key, Entry& outEntry);
	void Print();
	bool IsEmpty() const;

private:
	static const int bucketCount = 19;
	std::vector<Entry> table[bucketCount];
};

