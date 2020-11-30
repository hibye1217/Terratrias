#pragma once
#include "Topography.h"

class Space :
    public Topography
{
public:
    Space();
    ~Space();
    bool canGo();
};

