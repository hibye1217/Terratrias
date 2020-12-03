#pragma once
#include "stdafx.h"
#include "Topography.h"

Topography::Topography() : Topography(Enum::SPACE) {}

Topography::Topography(int type) : type(type)
//, Sprite("Resources/Sprite/Big/Space.png")    // 1
{
    sprite = nullptr;
}

Topography::Topography(int type, std::string path) : type(type)
//, Sprite(path.c_str())        // 2
{
    sprite = new Sprite(path.c_str());
}

Topography::~Topography() {}

int Topography::getType()
{
    return type;
}

void Topography::setSprite(Sprite* mySprite)
{
    sprite = mySprite;
}

Sprite* Topography::getSprite()
{
    return sprite;
}

void Topography::Render()
{
    sprite->Render();
}

void Topography::onArrived() {}
