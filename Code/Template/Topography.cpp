#pragma once
#include "stdafx.h"
#include "Topography.h"

Topography::Topography() : Topography(Enum::SPACE) {}

Topography::Topography(int type) : type(type)
, Sprite("Resources/Space.png")    // 1
{}

Topography::Topography(int type, std::string path) : type(type)
, Sprite(path.c_str())        // 2
{
}

Topography::~Topography() {}

int Topography::getType()
{
    return type;
}

void Topography::onArrived() {}
