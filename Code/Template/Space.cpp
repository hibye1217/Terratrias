#pragma once
#include "stdafx.h"
#include "Space.h"

Space::Space()
	: Topography(Enum::SPACE, "Resources/Sprite/Big/Space.png") {

}

Space::~Space() {}

bool Space::canGo()
{
	return true;
}
