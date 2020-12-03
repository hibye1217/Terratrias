#pragma once
#include "stdafx.h"
#include "Item.h"

Item::Item() : Item(Enum::NONE) {
}

Item::Item(int type) : type(type)
//, Sprite("Resources/Sprite/Big/Space.png")    // 1
{
    sprite = new Sprite(item_file_path[type].c_str());
}

Item::Item(int type, int id) : type(type)
//, Sprite(path.c_str())        // 2
{
    sprite = new Sprite(key_file_path[id].c_str());
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
