#pragma once
#include "Item.h"
#include "Hole.h"
#include "Manager.h"
#include "Const.h"

class Key :
    public Item
{
private:
    const int id;
public:
    Key();
    Key(int id);
    ~Key();
    void Render();
    int getId();
    void useItem();
    bool canUseItem();
};
