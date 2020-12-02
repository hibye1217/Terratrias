#pragma once
#include "stdafx.h"
#include "User.h"
#include "Manager.h"

User::User()
//    : Sprite("Resources/User.png")    // 1
{}

User::~User() {}

int User::getX() 
{
    return x;
}

void User::setX(int x) 
{
    this->x = x;
}

int User::getY() 
{
    return y;
}

void User::setY(int y) 
{
    this->y = y;
}

Item* User::getInventory() 
{
    return pInventory;
}

void User::setInventory(Item* inventory) 
{
    pInventory = inventory;
}

void User::useItem() 
{
    pInventory->useItem();
}

void User::gainItem() 
{
    User& user = manager.getUser();
    Item* item = manager.getCell(x, y).getItem();
    if(getInventory()->getType() != Enum::NONE || item->getType() == Enum::NONE)
    {
        return;
    }
    setInventory(item);
    manager.getCell(x, y).setItem(item_list[Enum::NONE]);
}

void User::putItem() 
{
    User& user = manager.getUser();
    Item* item = manager.getCell(user.getX(), user.getY()).getItem();
    if(getInventory()->getType() == Enum::NONE || item->getType() != Enum::NONE)
    {
        return;
    }
    manager.getCell(x, y).setItem(getInventory());
    setInventory(item_list[Enum::NONE]);
}

void User::move(int direction) 
{
    int nx = x + dx[direction];
    int ny = y + dy[direction];

    if (!manager.isValidPoint(nx, ny))
    {
        return;
    }

    if (!manager.getCell(nx, ny).canGo())
    {
        return;
    }
    
    x = nx;
    y = ny;

    //setPos(nx, ny);       // 2
    // 유저에 추가한거
    

    manager.setMoveCnt(manager.getMoveCnt() + 1);
}
