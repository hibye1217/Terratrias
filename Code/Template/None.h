#pragma once
#include "Item.h"

class None :
    public Item
{
public:
    None();
    void useItem();
    bool canUseItem();
};

