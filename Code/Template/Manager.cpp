#include <fstream>
#include "Manager.h"
#include "ItemList.h"
#include "TopographyList.h"

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

//Item& Manager::getCellItem(int x, int y) {
//    return map[x][y].getItem();
//}
//
//void Manager::setCellItem(int x, int y, Item& item) {
//    map[x][y].setItem(item);
//}
//
//Topography& Manager::getCellTopography(int x, int y) {
//    return map[x][y].getTopography();
//}
//
//void Manager::setCellTopography(int x, int y, Topography& topography) {
//    map[x][y].setTopography(topography);
//}

User& Manager::getUser()
{
    return user;
}

bool Manager::isValidPoint(int x, int y)
{
    return (0 <= x && x < height) && (0 <= y && y < width);
}

int Manager::getMoveCnt() {
    return moveCnt;
}

void Manager::setMoveCnt(int moveCnt) {
    this->moveCnt = moveCnt;
}

int Manager::getLimitCnt() {
    return limitCnt;
}

void Manager::setLimitCnt(int limitCnt) {
    this->limitCnt = limitCnt;
}

// not finished
void Manager::initialize(std::string filename) {
    // file io
    // map, limit
    // user x, y
    moveCnt = 0;
    user.setX(0);
    user.setY(0);
    user.setInventory(NONE);

    std::ifstream in;
    in.open(filename);
    in >> height >> width >> limitCnt;
    for (int i = 0; i < height; ++i)
    {
        map.emplace_back(std::vector<Cell>());
        for (int j = 0; j < width; ++j)
        {
            char ch;
            in >> ch;
            switch (ch)
            {
            case '.':
                // SPACE
                map.back().emplace_back(NONE, SPACE);
                break;

            case 'W':
                // WALL?
                break;
            }
        }
    }
    in.close();

}