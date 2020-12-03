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
	delete pItem;
	delete pTopography;
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

