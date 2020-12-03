#pragma once
#include "stdafx.h"
#include "Item.h"

Item::Item() : Item(Enum::NONE) {
}

Item::Item(int type) : type(type)
//, Sprite("Resources/Sprite/Big/None.png") // 1
{
    sprite = nullptr;
}

Item::Item(int type, std::string path) : type(type)
//, Sprite(path.c_str())    // 2
{
    sprite = new Sprite(path.c_str());
}

Item::~Item() {}

int Item::getType()
{
    return type;
}

void Item::setSprite(Sprite* mySprite)
{
    sprite = mySprite;
}

Sprite* Item::getSprite()
{
    return sprite;
}

void Item::Render()
{
    sprite->Render();
}
