#pragma once
#include <string>

class Item
{
private:
	const std::string symbol;
public:
	Item();
	Item(const std::string& symbol);
	//Item(Item& item);
	virtual void useItem() = 0;
	virtual bool canUseItem() = 0;
};

