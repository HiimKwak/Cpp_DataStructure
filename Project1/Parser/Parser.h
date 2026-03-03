#pragma once

#include <string>
#include "../Container/Vector.h"
#include "../Container/Card.h"

void LoadCards(const std::string& filename, Vector<Card>& cards);
