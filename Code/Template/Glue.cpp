#pragma once
#include "stdafx.h"
#include "Glue.h"
#include "Manager.h"

Glue::Glue() : Topography(Enum::GLUE) {}

Glue::~Glue() {}

void Glue::Render()
{
	Topography::Render();
}

bool Glue::canGo()
{
	return true;
}

void onArrived()
{
	manager.setLastDir(-1);
	manager.setMoved(false);
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}
