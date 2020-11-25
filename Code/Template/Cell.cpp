#include "Cell.h"

Cell::Cell() {
	pItem = nullptr;
	pTopography = nullptr;
}

Cell::Cell(Item& item, Topography& topography) {
	setItem(item);
	setTopography(topography);
}

Item& Cell::getItem(void) {
	return *pItem;
}

void Cell::setItem(Item& item) {
	pItem = &item;
}

Topography& Cell::getTopography(void) {
	return *pTopography;
}

void Cell::setTopography(Topography& topography) {
	pTopography = &topography;
}

bool Cell::canGo(void) {
	return pTopography->canGo();
}

