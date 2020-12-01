#pragma once
#include "Space.h"

Space::Space() : Topography(Enum::SPACE) {}

Space::~Space() {}

bool Space::canGo()
{
	return true;
}
