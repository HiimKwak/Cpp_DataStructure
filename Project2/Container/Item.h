#pragma once

#include <string>

struct Item
{
	std::string name;
	std::string type;
	int value;

	Item() : name(""), type(""), value(0) {}
	Item(const std::string& name, const std::string& type, int value)
		: name(name), type(type), value(value) {}
};
