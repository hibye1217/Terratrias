#pragma once
#include "Const.h"
#include "None.h"

None::None() : Item(Enum::NONE) {}

None::~None() {}

void None::useItem()
{
	return;
}

bool None::canUseItem()
{
	return false;
}