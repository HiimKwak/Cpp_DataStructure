#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <conio.h>
#include <iostream>
#include "Container/Vector.h"
#include "Container/Card.h"
#include "Common/Utils.h"
#include "Parser/Parser.h"

void render(const Vector<Card>& cards, int selected, int offset)
{
	system("cls");

	for (int i = 0; i < 20; ++i)
	{
		int idx = (offset + i) % cards.size();
		Util::PutCursorOnPosition(0, i + 1);
		if (idx == selected)
		{
			Util::ColorText(Util::Color::YELLOW);
			std::cout << "> ";

		}
		else
		{
			Util::ColorText(Util::Color::WHITE);
			std::cout << "  ";
		}
		std::cout << cards[idx].id << " " << cards[idx].name;
	}

	const Card& c = cards[selected];
	Util::PutCursorOnPosition(30, 1);
	std::cout << "ID   : " << c.id;
	Util::PutCursorOnPosition(30, 2);
	std::cout << "Name : " << c.name;
	Util::PutCursorOnPosition(30, 3);
	std::cout << "Type : " << c.type;
	Util::PutCursorOnPosition(30, 4);
	std::cout << "Cost : " << c.cost;
	Util::PutCursorOnPosition(30, 5);
	std::cout << "Rarity : " << c.rarity;

}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Vector<Card> deck;
	LoadCards("data.txt", deck);

	std::cout << "Loaded " << deck.size() << " cards successfully!\n";

	int selected = 0;
	while (true)
	{
		render(deck, selected, (selected - 2 + (int)deck.size()) % (int)deck.size());

		int ch = _getch();
		if (ch == 0xE0) {
			ch = _getch();
			if (ch == 72)
				selected = (selected - 1 + deck.size()) % deck.size();
			if (ch == 80)
				selected = (selected + 1) % deck.size();
		}
		if (ch == 27 || ch == 113) break;
	}
}