#pragma once

#include "LinkedList.h"
#include "Item.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class HashTable
{
public:
	HashTable(int capacity = 101) : capacity(capacity) // 캐퍼시티에 소수(prime number) 사용
	{
		buckets.resize(capacity);
	}

	~HashTable()
	{
		for (int i = 0; i < capacity; ++i)
		{
			buckets[i].Clear();
		}
	}

	bool LoadFromFile(const std::string& filename)
	{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			return false;
		}

		std::string line;
		std::getline(file, line); // 헤더 스킵 (name,type,value)

		while (std::getline(file, line))
		{
			std::stringstream ss(line);
			std::string name, type, valueStr;

			std::getline(ss, name, ',');
			std::getline(ss, type, ',');
			std::getline(ss, valueStr, ',');

			int value = std::stoi(valueStr);
			Add(name, type, value);
		}

		file.close();
		return true;
	}

	void Add(const std::string& name, const std::string& type, int value)
	{
		int index = Hash(name);
		Item item(name, type, value);
		buckets[index].Add(name, item);
	}

	Item* Find(const std::string& name)
	{
		int index = Hash(name);
		Node<std::string, Item>* node = buckets[index].Find(name);
		if (node)
		{
			return const_cast<Item*>(&node->GetData().GetValue());
		}
		return nullptr;
	}

	bool Remove(const std::string& name)
	{
		int index = Hash(name);
		return buckets[index].Remove(name);
	}

	void List() const
	{
		for (int i = 0; i < capacity; ++i)
		{
			Node<std::string, Item>* current = buckets[i].GetHead();
			while (current)
			{
				const Item& item = current->GetData().GetValue();
				std::cout << "Name: " << item.name
					<< ", Type: " << item.type
					<< ", Value: " << item.value << "\n";
				current = current->GetNext();
			}
		}
	}

private:
	int Hash(const std::string& key) const
	{
		unsigned int hash = 0;
		for (char c : key)
		{
			hash = hash * 31 + c;
		}
		return hash % capacity;
	}

private:
	std::vector<LinkedList<std::string, Item>> buckets;
	int capacity;
};

