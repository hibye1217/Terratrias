#pragma once
#include "stdafx.h"
#include "Topography.h"

Topography::Topography() : Topography(Enum::SPACE) {}

Topography::Topography(int type) : type(type)
//, Sprite("Resources/Sprite/Big/Space.png")    // 1
{
    sprite = new Sprite(topo_file_path[type].c_str());
}

Topography::Topography(int type, int id) : type(type)
//, Sprite(path.c_str())        // 2
{
    sprite = new Sprite(hole_file_path[id].c_str());
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

void Topography::onArrived()
{
    manager.setLastDir(-1);
    manager.setMoved(false);
}
