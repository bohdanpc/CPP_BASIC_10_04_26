#pragma once
#include <vector>

class Item;	//forward declaration

class ItemDeck
{
public:
	ItemDeck();
	~ItemDeck();

	std::vector<Item*> generateItems() const;

private:
	std::vector<Item*> m_itemsDataBase;
};