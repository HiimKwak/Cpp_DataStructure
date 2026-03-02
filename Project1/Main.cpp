#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include "Container/Vector.h"
#include "Container/Card.h"
#include "Parser.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Vector<Card> cards;
    load_cards(cards, "data.txt");

    std::cout << "Loaded " << cards.size() << " cards.\n";

    for (size_t i = 0; i < cards.size(); ++i)
    {
        const Card& c = cards[i];
        std::cout << c.id << ": " << c.name << " [" << c.type << "]\n";
    }
}