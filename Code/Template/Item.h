#pragma once
#include <string>
#include "Const.h"

class Item
{
private:
	int type;
public:
	Item();
	Item(int type);
	virtual ~Item();
	int getType();
	virtual void useItem() = 0;
	virtual bool canUseItem() = 0;
	Item& operator = (const Item&) = default;
};
