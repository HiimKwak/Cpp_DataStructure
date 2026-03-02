#pragma once

#include <string>

class Card
{
public:
    int id;
    std::string name;
    std::string type;
    int cost;
    int rarity;

    Card() = default;

    Card(int _id, const std::string& _name, const std::string& _type, int _cost, int _rarity)
        : id(_id), name(_name), type(_type), cost(_cost), rarity(_rarity) {
    }
};