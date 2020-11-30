#pragma once
#include "Item.h"

class User
{
private:
	int x, y;
	Item* pInventory;
public:
	User();
	~User();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	Item* getInventory();
	void setInventory(Item* item);

	void useItem();
	void gainItem();
	void putItem();
	void move(int direction);
};

