#pragma once

template<typename Key, typename Value>
class Pair
{
public:
	Pair() = default;
	Pair(const Key& key, const Value& value) : key(key), value(value) {}

	const Key& GetKey() const { return key; }
	const Value& GetValue() const { return value; }

private:
	Key key;
	Value value;
};
