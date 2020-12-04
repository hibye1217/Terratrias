#pragma once
#include "stdafx.h"
#include "User.h"
#include "Manager.h"

User::User()
//    : Sprite("Resources/User.png")    // 1
{
    sprite = nullptr;
}

User::~User() {
    delete sprite;
}

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

void User::setMargins(int x, int y)
{
    margin_x = x;
    margin_y = y;
}

int User::getMargin2()
{
    return margin_x;
}

int User::getMargin1()
{
    return margin_y;
}

Item* User::getInventory() 
{
    return pInventory;
}

void User::setInventory(Item* inventory) 
{
    pInventory = inventory;
}

void User::setSprite(Sprite* mySprite)
{
    sprite = mySprite;
}

Sprite* User::getSprite()
{
    return sprite;
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
    Item* tmp = getInventory();
    setInventory(item);
    manager.getCell(x, y).setItem(tmp);
    //manager.getCell(x, y).setItem(item_list[Enum::NONE]);
}

void User::putItem() 
{
    User& user = manager.getUser();
    Item* item = manager.getCell(user.getX(), user.getY()).getItem();
    if(getInventory()->getType() == Enum::NONE || item->getType() != Enum::NONE)
    {
        return;
    }
    Item* tmp = getInventory();
    setInventory(item);
    manager.getCell(x, y).setItem(tmp);
    //setInventory(item_list[Enum::NONE]);
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
    manager.setLastDir(direction);
    manager.setMoved(true);

    sprite->setPos(margin_x + (y * i_hat), margin_y + (x * j_hat));       // 2
    // 유저에 추가한거
    

    manager.setMoveCnt(manager.getMoveCnt() + 1);
    //system("cls");
    //std::cout << "remain key: " << manager.getKeyCnt() << std::endl;
    //std::cout << "remain count: " << manager.getLimitCnt() - manager.getMoveCnt() << std::endl;
    //std::cout << "(x, y) = " << x << ' ' << y << std::endl;
    //std::cout << "inventory: " << item_name[getInventory()->getType()] << std::endl << std::endl;
    //for (int i = 0; i < manager.getHeight(); ++i)
    //{
    //    for (int j = 0; j < manager.getWidth(); ++j)
    //    {
    //        //std::cout << manager.getCell(i, j).getTopography()->getType() << ' ';
    //        std::cout << topo_name[manager.getCell(i, j).getTopography()->getType()] << ' ';
    //    }
    //    std::cout << std::endl;
    //}
    //std::cout << std::endl;
    //for (int i = 0; i < manager.getHeight(); ++i)
    //{
    //    for (int j = 0; j < manager.getWidth(); ++j)
    //    {
    //        std::cout << item_name[manager.getCell(i, j).getItem()->getType()] << ' ';
    //    }
    //    std::cout << std::endl;
    //}
}
