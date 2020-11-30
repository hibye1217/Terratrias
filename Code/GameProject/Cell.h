#pragma once
#include "Item.h"
#include "Topography.h"
#include "Const.h"

class Cell
{
private:
	Item* pItem;
	Topography* pTopography;
public:
	Cell();
	Cell(Item* item, Topography* topography);
	~Cell();

	Item* getItem(void);
	void setItem(Item* item);
	Topography* getTopography(void);
	void setTopography(Topography* topography);
	bool canGo(void);
};
