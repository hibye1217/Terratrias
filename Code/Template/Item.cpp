#pragma once
#include "stdafx.h"
#include "Item.h"

Item::Item() : Item(Enum::NONE) {
}

Item::Item(int type) : type(type), Sprite("Resources/None.png") {

}

Item::Item(int type, std::string path) : type(type), Sprite(path.c_str())
{
}

Item::~Item() {}

int Item::getType()
{
    return type;
}
