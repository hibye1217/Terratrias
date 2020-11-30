#pragma once
#include "Item.h"
#include "Const.h"

class None :
    public Item
{
public:
    None();
    ~None();
    void useItem();
    bool canUseItem();
};
