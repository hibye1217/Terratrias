#pragma once
#include "Topography.h"
#include "Const.h"

class Wall :
    public Topography
{
public:
    Wall();
    ~Wall();
    bool canGo();
};
