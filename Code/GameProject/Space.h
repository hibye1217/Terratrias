#pragma once
#include "Topography.h"
#include "Const.h"

class Space :
    public Topography
{
public:
    Space();
    ~Space();
    bool canGo();
};