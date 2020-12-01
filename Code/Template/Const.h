#pragma once
#include <string>

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };
const int dx8[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
const int dy8[] = { -1, 0, 1, 1, 1, 0, -1, -1 };

namespace Enum
{
    enum Direction {
        UP,
        RIGHT,
        DOWN,
        LEFT,
    };

    enum ItemList 
    {
        KEY,
        NONE,
        JUMP,
        BOOST,
        BOMB,
    };

    enum TopoList
    {
        HOLE,
        SPACE,
        WALL,
        GLUE,
    };
}

const int item_num = 5;

const std::string item_name[item_num] {
    "Key",
    "None",
    "Jump",
    "Boost",
    "Bomb",
};

const int topo_num = 4;

const std::string topo_name[topo_num] = {
    "Hole",
    "Space",
    "Wall",
    "Glue",
};

class Manager;
class Item;
class Topography;

extern Manager manager;
extern Item* item_list[item_num];
extern Topography* topo_list[topo_num];
