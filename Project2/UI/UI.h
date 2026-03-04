#pragma once

#include <vector>
#include "../Container/HashTable.h"
#include "../Container/Item.h"

void RenderUI(const std::vector<Item>& items, int selected, int offset);
void CommandMode(HashTable& itemDict);
