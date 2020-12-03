#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "stdafx.h"
#include "Manager.h"
#include "Const.h"

Manager::Manager() : height(0), width(0), limitCnt(0), moveCnt(0), keyCnt(0), scaleRatio(0), lastDir(-1), moved(false) {}

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

void Manager::setScaleRatio(float Ratio)
{
    scaleRatio = Ratio;
    return;
}

float Manager::getScaleRatio()
{
    return scaleRatio;
}

void Manager::setLastDir(int dir)
{
    lastDir = dir;
}

int Manager::getLastDir()
{
    return lastDir;
}

void Manager::setMoved(bool moved)
{
    this->moved = moved;
}

bool Manager::getMoved()
{
    return moved;
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
    user.setInventory(new None());
    //user.setInventory(item_list[Enum::NONE]);

    FILE* in = fopen(filename.c_str(), "r");
    //std::ifstream in(filename);
    //in.open(filename, std::ios::in);
    //in >> height >> width >> limitCnt >> keyCnt;
    //std::cin >> height >> width >> limitCnt >> keyCnt;
    fscanf(in, "%d%d%d%d", &height, &width, &limitCnt, &keyCnt);
    map.resize(height);
    for (auto& v : map)
    {
        v.resize(width);
    }

    int margin_1 = min((SCREEN_HEIGHT - (SCREEN_HEIGHT % height)) / height, 150);
    int margin_2 = min((SCREEN_WIDTH - (SCREEN_WIDTH % width)) / width, 150);

    i_hat = margin_1 < margin_2 ? margin_1 : margin_2;
    j_hat = i_hat;



    margin_1 = (SCREEN_HEIGHT - (height * j_hat)) / 2;
    margin_2 = (SCREEN_WIDTH - (width * i_hat)) / 2;

    // Item과 Topography setPos 하기
    // StageScene Render 손보기

    user.setMargins(margin_2, margin_1);
    setScaleRatio((float)i_hat / (float)2953);

    int userX, userY;
    //in >> userX >> userY;
    //std::cin >> userX >> userY;
    fscanf(in, "%d%d", &userX, &userY);
    user.setX(userX);
    user.setY(userY);

    user.getSprite()->setPos(margin_2 + (userY * i_hat), margin_1 + (userX * j_hat));    // 1
    user.getSprite()->setScale(scaleRatio, scaleRatio);

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
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
                //map[i][j].getTopography()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));  // 2
                map[i][j].getTopography()->getSprite()->setScale(scaleRatio, scaleRatio);
            }
            else
            {
                for (int k = 1; k < topo_num; ++k)
                {
                    if (!strcmp(topo, topo_name[k].c_str()))
                    {
                        if (k == Enum::SPACE) {
                            map[i][j].setTopography(new Space());
                        }
                        else if (k == Enum::WALL) {
                            map[i][j].setTopography(new Wall());
                        }
                        else if (k == Enum::GLUE) {
                            map[i][j].setTopography(new Glue());
                        }
                        //else {
                        //    map[i][j].setTopography(new Ice());
                        //}

                        //map[i][j].getTopography()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));  // 2
                        map[i][j].getTopography()->getSprite()->setScale(scaleRatio, scaleRatio);
                        break;
                    }
                }
            }
        }
    }

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            //std::string item;
            //in >> item;
            //std::cin >> item;
            //std::cout << item << ' ';
            char item[16];
            fscanf(in, "%s", item);
            //if(item == "Key")
            if (!strcmp(item, "Key"))
            {
                int id;
                //in >> id;
                //std::cin >> id;
                fscanf(in, "%d", &id);
                map[i][j].setItem(new Key(id));
                //map[i][j].getItem()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));    // 3
                map[i][j].getItem()->getSprite()->setScale(scaleRatio, scaleRatio);
            }
            else
            {
                for (int k = 1; k < item_num; ++k)
                {
                    if (!strcmp(item, item_name[k].c_str()))
                    {
                        //std::cout << k << ' ';
                        if (k == Enum::NONE) {
                            map[i][j].setItem(new None());
                        }
                        else if (k == Enum::JUMP) {
                            map[i][j].setItem(new Jump());
                        }
                        else if (k == Enum::BOOST) {
                            map[i][j].setItem(new Boost());
                        }
                        else if (k == Enum::BOMB) {
                            map[i][j].setItem(new Bomb());
                        }
                        //map[i][j].getItem()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));    // 3
                        map[i][j].getItem()->getSprite()->setScale(scaleRatio, scaleRatio);
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
    for (auto& v : map)
    {
        //for (auto& cell : v)
        //{
        //    delete cell.getItem();
        //    delete cell.getTopography();
        //}
        // Cell 소멸자에서 delete 해줌
        v.clear();
        // 하나씩 딜리트해야할거같은데
        //for (auto& b : v) {
        //    SAFE_DELETE(b);
        //}
    }
    map.clear();
}
