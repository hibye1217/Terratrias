#pragma once
#include "stdafx.h"
#include "None.h"

None::None() : Item(Enum::NONE, "Resources/None.png") {}

None::~None() {}

void None::useItem()
{
	return;
}

bool None::canUseItem()
{
	return false;
}
