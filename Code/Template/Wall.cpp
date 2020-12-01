#pragma once
#include "stdafx.h"
#include "Wall.h"

Wall::Wall() : Topography(Enum::WALL) {}

Wall::~Wall() {}

bool Wall::canGo()
{
	return false;
}
