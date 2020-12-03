#pragma once
#include "stdafx.h"
#include "Wall.h"

Wall::Wall() : Topography(Enum::WALL, "Resources/Sprite/Big/Wall.png") {}

Wall::~Wall() {}

void Wall::Render()
{
	Topography::Render();
}

bool Wall::canGo()
{
	return false;
}
