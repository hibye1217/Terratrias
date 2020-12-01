#pragma once
#include "stdafx.h"
#include "Cell.h"

Cell::Cell()
{
	pItem = nullptr;
	pTopography = nullptr;
}

Cell::Cell(Item* item, Topography* topography)
{
	setItem(item);
	setTopography(topography);
}

Cell::~Cell()
{
	bool valid = false;
	for (int i = 0; i < item_num; ++i)
	{
		if (pItem == item_list[i])
		{
			valid = true;
			break;
		}
	}
	if (!valid)
	{
		delete pItem;
	}
	
	valid = false;
	for (int i = 0; i < topo_num; ++i)
	{
		if (pTopography == topo_list[i])
		{
			valid = true;
			break;
		}
	}
	if (!valid)
	{
		delete pTopography;
	}
}

Item* Cell::getItem(void)
{
	return pItem;
}

void Cell::setItem(Item* pItem) 
{
	this->pItem = pItem;
}

Topography* Cell::getTopography(void)
{
	return pTopography;
}

void Cell::setTopography(Topography* pTopography)
{
	this->pTopography = pTopography;
}

bool Cell::canGo(void)
{
	return pTopography->canGo();
}

