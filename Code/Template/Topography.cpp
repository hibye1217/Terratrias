#pragma once
#include "stdafx.h"
#include "Topography.h"

Topography::Topography() : Topography(Enum::SPACE) {}

Topography::Topography(int type) : type(type), Sprite("Resource/Space.png") {}

Topography::Topography(int type, std::string path) : type(type), Sprite(path.c_str())
{
}

Topography::~Topography() {}

int Topography::getType()
{
    return type;
}

void Topography::onArrived() {}
