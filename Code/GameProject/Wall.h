#pragma once
#include "Topography.h"

class Wall :
    public Topography
{
public:
    Wall();
    ~Wall();
    bool canGo();
};
