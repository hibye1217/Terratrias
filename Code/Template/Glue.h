#pragma once
#include "Topography.h"
#include "Const.h"

class Glue :
    public Topography
{
public:
    Glue();
    ~Glue();
    void Render();
    void onArrived();
    bool canGo();
};
