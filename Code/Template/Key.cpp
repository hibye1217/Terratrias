#pragma once
#include "stdafx.h"
#include "Key.h"

Key::Key() : Key(-1) {}

Key::Key(int id) : id(id), Item(Enum::KEY, id){}

Key::~Key() {}

void Key::Render()
{
    Item::Render();
}

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
    user.setInventory(new None());
    //user.setInventory(item_list[Enum::NONE]);

    Cell& cell = manager.getCell(user.getX(), user.getY());
    delete cell.getTopography();
    cell.setTopography(new Space());
    //cell.setTopography(topo_list[Enum::SPACE]);

    //manager.setMoveCnt(manager.getMoveCnt() + 1);
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
