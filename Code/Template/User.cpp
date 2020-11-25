#pragma once
#include "User.h"
#include "ItemList.h"
#include "Manager.h"

extern Manager manager;

int User::getX() {
    return x;
}

void User::setX(int x) {
    this->x = x;
}

int User::getY() {
    return y;
}

void User::setY(int y) {
    this->y = y;
}

Item& User::getInventory() {
    return *pInventory;
}

void User::setInventory(Item& inventory) {
    pInventory = &inventory;
}

void User::useItem() {
    pInventory->useItem();
}

void User::gainItem() {
    if((&manager.getCell(x, y).getItem() == &NONE) || (&getInventory() != &NONE)) {
        return;
    }
    setInventory(manager.getCell(x, y).getItem());
    manager.getCell(x, y).setItem(NONE);
}

void User::putItem() {
    if((&manager.getCell(x, y).getItem() != &NONE) || (&getInventory() == &NONE)) {
        return;
    }
    manager.getCell(x, y).setItem(getInventory());
    setInventory(NONE);
}

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

void User::move(int direction) {
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
}
