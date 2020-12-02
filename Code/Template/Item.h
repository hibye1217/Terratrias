#pragma once
#include <string>
#include "Const.h"
#include "Sprite.h"

class Item : public Sprite
{
private:
	int type;
public:
	Item();
	Item(int type);
	Item(int type, std::string path);
	virtual ~Item();
	int getType();
	virtual void useItem() = 0;
	virtual bool canUseItem() = 0;
	Item& operator = (const Item&) = default;
};
