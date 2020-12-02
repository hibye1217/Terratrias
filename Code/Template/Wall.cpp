#pragma once
#include "stdafx.h"
#include "Wall.h"

Wall::Wall() : Topography(Enum::WALL, "Resources/Wall.png") {}

Wall::~Wall() {}

bool Wall::canGo()
{
	return false;
}
