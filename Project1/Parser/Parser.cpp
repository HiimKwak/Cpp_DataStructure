#include "Parser.h"

#include <fstream>
#include <sstream>

#include "../Container/Vector.h"
#include "../Container/Card.h"

void LoadCards(const std::string& filename, Vector<Card>& cards)
{
	std::ifstream file(filename);
	if (!file.is_open()) return;

	std::string line;

	std::getline(file, line); // 첫 줄 헤더 건너뛰기

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string id_str, name, type, cost_str, rarity_str;

		std::getline(ss, id_str, ',');
		std::getline(ss, name, ',');
		std::getline(ss, type, ',');
		std::getline(ss, cost_str, ',');
		std::getline(ss, rarity_str, ',');

		int id = std::stoi(id_str);
		int cost = std::stoi(cost_str);
		int rarity = std::stoi(rarity_str);

		cards.push_back(Card(id, name, type, cost, rarity));
	}
}