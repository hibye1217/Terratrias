#pragma once
#include <string>
#include "stdafx.h"

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
        ICE,
        GLUE,
    };
}

const int item_num = 5;

const std::string item_name[item_num]{
    "Key",
    "None",
    "Jump",
    "Boost",
    "Bomb",
};

const std::string item_file_path[item_num] = {
    "Resources/Sprite/Big/Key1.png",
    "Resources/Sprite/Big/None.png",
    "Resources/Sprite/Big/Jump.png",
    "Resources/Sprite/Big/Boost.png",
    "Resources/Sprite/Big/Bomb.png",
};

const int topo_num = 5;

const std::string topo_name[topo_num] = {
    "Hole",
    "Space",
    "Wall",
    "Ice",
    "Glue",
};

const std::string topo_file_path[topo_num] = {
    "Resources/Sprite/Big/Hole1.png",
    "Resources/Sprite/Big/Space.png",
    "Resources/Sprite/Big/Wall.png",
    "Resources/Sprite/Big/Ice.png",
    "Resources/Sprite/Big/Glue.png",
};

const int max_key_count = 5;

const std::string hole_file_path[max_key_count + 1] = {
    "Resources/Sprite/Big/Hole1.png",
    "Resources/Sprite/Big/Hole1.png",
    "Resources/Sprite/Big/Hole2.png",
    "Resources/Sprite/Big/Hole3.png",
    "Resources/Sprite/Big/Hole4.png",
    "Resources/Sprite/Big/Hole5.png",
};

const std::string key_file_path[max_key_count + 1] = {
    "Resources/Sprite/Big/Key1.png",
    "Resources/Sprite/Big/Key1.png",
    "Resources/Sprite/Big/Key2.png",
    "Resources/Sprite/Big/Key3.png",
    "Resources/Sprite/Big/Key4.png",
    "Resources/Sprite/Big/Key5.png",
};

class Manager;
class Item;
class Topography;

extern Manager manager;
extern Item* item_list[item_num];
extern Topography* topo_list[topo_num];
