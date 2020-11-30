#pragma once
#include <typeinfo>
#include "Const.h"
#include "Key.h"
#include "Manager.h"
#include "Hole.h"

Key::Key() : Key(-1) {}

Key::Key(int id) : Item(Enum::KEY), id(id) {}

Key::~Key() {}

int Key::getId()
{
    return id;
}

void Key::useItem() 
{
    if(!canUseItem()) 
    {
        return;
    }

    User& user = manager.getUser();
    delete user.getInventory();
    user.setInventory(item_list[Enum::NONE]);

    Cell& cell = manager.getCell(user.getX(), user.getY());
    delete cell.getTopography();
    cell.setTopography(topo_list[Enum::SPACE]);

    manager.setMoveCnt(manager.getMoveCnt() + 1);
    manager.setKeyCnt(manager.getKeyCnt() - 1);
}

bool Key::canUseItem() {
    User& user = manager.getUser();
    Topography* topo = manager.getCell(user.getX(), user.getY()).getTopography();
    if(topo->getType() == Enum::HOLE)
    {
        return (id == dynamic_cast<Hole&>(*topo).getId());
    }
    return false;
}
