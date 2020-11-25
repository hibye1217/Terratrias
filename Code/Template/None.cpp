#pragma once
#include "None.h"

None::None() : Item("") {}

void None::useItem() {
	return;
}

bool None::canUseItem() {
	return false;
}