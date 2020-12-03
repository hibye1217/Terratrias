#pragma once
#include "stdafx.h"
#include "Glue.h"
#include "Manager.h"

Glue::Glue() : Topography(Enum::GLUE, "Resources/Sprite/Big/Glue.png") {}

Glue::~Glue() {}

bool Glue::canGo()
{
	return true;
}

void onArrived()
{
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}
