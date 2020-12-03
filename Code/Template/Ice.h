#pragma once
#include "Topography.h"
class Ice :
    public Topography
{
public:
    Ice();
    ~Ice();
    void Render();
    bool canGo();
};

