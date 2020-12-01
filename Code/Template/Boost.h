#pragma once
#include "Item.h"
#include "Manager.h"
#include "Const.h"

class Boost :
    public Item
{
private:
    int direction;
public:
    Boost();
    ~Boost();
    void useItem();
    bool canUseItem();
};
