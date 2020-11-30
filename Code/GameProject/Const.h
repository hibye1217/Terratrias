#pragma once
#include <string>
#include "Manager.h"
#include "None.h"
#include "Key.h"
#include "Space.h"

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

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
    };

    enum TopoList
    {
        HOLE,
        SPACE,
        WALL,
    };
}

const int item_num = 2;

const std::string item_name[item_num] {
    "KEY",
    "NONE",
};

const int topo_num = 3;

const std::string topo_name[topo_num] = {
    "HOLE",
    "SPACE",
    "WALL",
};

extern Manager manager;

extern Item* item_list[item_num];
extern Topography* topo_list[topo_num];

// extern None NONE;
// // Jump JUMP;

// extern Space SPACE;
