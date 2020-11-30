#pragma once
#include "Topography.h"

Topography::Topography() : Topography(Enum::SPACE) {}

Topography::Topography(int type) : type(type) {}

Topography::~Topography() {}

int Topography::getType()
{
    return type;
}

void Topography::onArrived() {}
