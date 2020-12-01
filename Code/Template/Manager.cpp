#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "stdafx.h"
#include "Manager.h"
#include "Const.h"

Manager::Manager() {}

Manager::~Manager() {}

Cell& Manager::getCell(int x, int y)
{
    if (!isValidPoint(x, y))
    {
        fprintf(stderr, "invalid access in getCell");
        exit(-1);
    }
    return map[x][y];
}

void Manager::setCell(int x, int y, Cell& cell)
{
    if (!isValidPoint(x, y))
    {
        fprintf(stderr, "invalid access in setCell");
        exit(-1);
    }
    map[x][y].setItem(cell.getItem());
    map[x][y].setTopography(cell.getTopography());
}

int Manager::getHeight()
{
    return height;
}

int Manager::getWidth()
{
    return width;
}

User& Manager::getUser()
{
    return user;
}

bool Manager::isValidPoint(int x, int y)
{
    return (0 <= x && x < height) && (0 <= y && y < width);
}

int Manager::getMoveCnt() 
{
    return moveCnt;
}

void Manager::setMoveCnt(int moveCnt) 
{
    this->moveCnt = moveCnt;
}

int Manager::getLimitCnt() 
{
    return limitCnt;
}

void Manager::setLimitCnt(int limitCnt) 
{
    this->limitCnt = limitCnt;
}

int Manager::getKeyCnt()
{
    return keyCnt;
}

void Manager::setKeyCnt(int keyCnt)
{
    this->keyCnt = keyCnt;
}


void Manager::initialize(std::string filename) 
{
    // file io
    /*
        height width limitCount keyCount
        userX userY
        Map Topographies
        Map Items

        5 4 10 1
        0 0

        Space Space Space Space
        Wall  Wall  Wall  Space
        Hole 1 Wall  Space Space
        Space Wall  Wall  Space
        Space Space Space Space

        None  None  None  None
        None  None  None  None
        None  None  Key 1  None
        None  None  None  None
        None  None  None  None
    */
    moveCnt = 0;
    user.setInventory(item_list[Enum::NONE]);

    std::ifstream in;
    in.open(filename);
    in >> height >> width >> limitCnt >> keyCnt;
    map.resize(height);
    for(auto& v : map)
    {
        v.resize(width);
    }

    int userX, userY;
    in >> userX >> userY;
    user.setX(userX);
    user.setY(userY);

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            std::string topo;
            in >> topo;
            if(topo == "Hole")
            {
                int id;
                in >> id;
                map[i][j].setTopography(new Hole(id));
            }
            else
            {
                for(int k = 1; k < topo_num; ++k)
                {
                    if(topo == topo_name[k])
                    {
                        map[i][j].setTopography(topo_list[k]);
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            std::string item;
            in >> item;
            //std::cout << item << ' ';
            if(item == "Key")
            {
                int id;
                in >> id;
                map[i][j].setItem(new Key(id));
            }
            else
            {
                for(int k = 1; k < item_num; ++k)
                {
                    if(item == item_name[k])
                    {
                        //std::cout << k << ' ';
                        map[i][j].setItem(item_list[k]);
                        break;
                    }
                }
            }
        }
        //std::cout << std::endl;
    }

    in.close();
}

void Manager::finalize()
{
   for(auto& v : map)
   {
       v.clear();
   }
   map.clear();
}
