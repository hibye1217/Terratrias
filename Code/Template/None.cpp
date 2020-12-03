#pragma once
#include "stdafx.h"
#include "None.h"

None::None() : 
	Item(Enum::NONE, "Resources/Sprite/Big/None.png") {}

None::~None() {}

void None::Render()
{
	Item::Render();
}

void None::useItem()
{
	return;
}

bool None::canUseItem()
{
	return false;
}
