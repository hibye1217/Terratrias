#pragma once
#include "stdafx.h"
#include "Topography.h"
class Ice :
    public Topography
{
public:
    Ice();
    ~Ice();
    void Render();
    void onArrived();
    bool canGo();
};

