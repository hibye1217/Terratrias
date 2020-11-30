#pragma once
#include "Item.h"

class None :
    public Item
{
public:
    None();
    ~None();
    void useItem();
    bool canUseItem();
};

