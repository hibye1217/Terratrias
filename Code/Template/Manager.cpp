#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "stdafx.h"
#include "Manager.h"
#include "Const.h"

Manager::Manager() : height(0), width(0), limitCnt(0), moveCnt(0), keyCnt(0) {}

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

    FILE* in = fopen(filename.c_str(), "r");
    //std::ifstream in(filename);
    //in.open(filename, std::ios::in);
    //in >> height >> width >> limitCnt >> keyCnt;
    //std::cin >> height >> width >> limitCnt >> keyCnt;
    fscanf(in, "%d%d%d%d", &height, &width, &limitCnt, &keyCnt);
    map.resize(height);
    for(auto& v : map)
    {
        v.resize(width);
    }

    int margin_1 = min((SCREEN_HEIGHT - (SCREEN_HEIGHT % height)) / height, 50);
    int margin_2 = min((SCREEN_WIDTH - (SCREEN_WIDTH % width)) / width, 50);

    i_hat = margin_1 < margin_2 ? margin_1 : margin_2;
    j_hat = i_hat;

    // Item과 Topography setPos 하기
    // StageScene Render 손보기


    int userX, userY;
    //in >> userX >> userY;
    //std::cin >> userX >> userY;
    fscanf(in, "%d%d", &userX, &userY);
    user.setX(userX);
    user.setY(userY);

    for(int i = 0; i < height; ++i)
    {
        for(int j = 0; j < width; ++j)
        {
            //std::string topo;
            //in >> topo;
            //std::cin >> topo;
            char topo[16];
            fscanf(in, "%s", topo);
            //if(topo == "Hole")
            if (!strcmp(topo, "Hole"))
            {
                int id;
                //in >> id;
                //std::cin >> id;
                fscanf(in, "%d", &id);
                map[i][j].setTopography(new Hole(id));
                map[i][j].getTopography()->setPos(SCREEN_WIDTH - i_hat * (width - j), SCREEN_HEIGHT - j_hat * (height - i));
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
            //std::string item;
            //in >> item;
            //std::cin >> item;
            //std::cout << item << ' ';
            char item[16];
            fscanf(in, "%s", item);
            //if(item == "Key")
            if(!strcmp(item, "Key"))
            {
                int id;
                //in >> id;
                //std::cin >> id;
                fscanf(in, "%d", &id);
                map[i][j].setItem(new Key(id));
                map[i][j].getItem()->setPos(SCREEN_WIDTH - i_hat * (width - j), SCREEN_HEIGHT - j_hat * (height - i));
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

    //in.close();
    fclose(in);
}

void Manager::finalize()
{
   for(auto& v : map)
   {
       v.clear();
   }
   map.clear();
}
