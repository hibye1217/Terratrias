#pragma once
#include "Glue.h"
#include "Manager.h"

Glue::Glue() : Topography(Enum::GLUE) {}

Glue::~Glue() {}

bool Glue::canGo()
{
	return true;
}

void onArrived()
{
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}
