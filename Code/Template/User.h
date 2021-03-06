#pragma once
#include "Item.h"
#include "Const.h"

class User
//	: public Sprite		// 1
{
private:
	int x, y;
	int margin_x, margin_y;
	Item* pInventory;
	Sprite* sprite;
public:
	User();
	~User();

	int getX();
	void setX(int x);
	int getY();
	void setY(int y);
	void setMargins(int x, int y);
	int getMargin2();
	int getMargin1();
	Item* getInventory();
	void setInventory(Item* item);
	void setSprite(Sprite*);
	Sprite* getSprite();

	void useItem();
	void gainItem();
	void putItem();
	void move(int direction);
};
