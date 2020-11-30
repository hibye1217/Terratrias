#include "Const.h"
#include "Item.h"

Item::Item() : Item(Enum::NONE) {}

Item::Item(int type) : type(type) {}

Item::~Item() {}

int Item::getType()
{
    return type;
}
