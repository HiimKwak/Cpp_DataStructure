#pragma once

template<typename KeyType, typename ValueType>
class Pair
{
public:
	KeyType key;
	ValueType value;

public:
	Pair() : key(), value() {}
	Pair(const KeyType& key, const ValueType& value) : key(key), value(value) {}

	bool operator==(const Pair<KeyType, ValueType>& other)
	{
		return key == other.key && value == other.value;
	}
	bool operater!=(const Pair<KeyType, ValueType>& other)
	{
		return !(*this == other);
	}
	bool operator>(const Pair<KeyType, ValueType>& other)
	{
		return key > other.key;
	}
	bool operator<(const Pair<KeyType, ValueType>& other)
	{
		return key < other.key;
	}
	bool operator>=(const Pair<KeyType, ValueType>& other)
	{
		return key >= other.key;
	}
	bool operator<=(const Pair<KeyType, ValueType>& other)
	{
		return key <= other.key;
	}
};