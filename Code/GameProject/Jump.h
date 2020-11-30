#pragma once
#include "Item.h"
#include "Manager.h"
#include "Const.h"

class Jump :
    public Item
{
private:
    int direction;
public:
    Jump();
    ~Jump();
    void useItem();
    bool canUseItem();
};
