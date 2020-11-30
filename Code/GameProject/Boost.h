#pragma once
#include "Item.h"

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
