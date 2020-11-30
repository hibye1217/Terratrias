#pragma once
#include "Item.h"
#include "Manager.h"
#include "Const.h"

class Bomb :
    public Item
{
public:
    Bomb();
    ~Bomb();
    void useItem();
    bool canUseItem();
};

