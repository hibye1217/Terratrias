#pragma once
#include "stdafx.h"
#include "Space.h"

Space::Space()
	: Topography(Enum::SPACE) {

}

Space::~Space() {}

void Space::Render()
{
	Topography::Render();
}

bool Space::canGo()
{
	return true;
}
