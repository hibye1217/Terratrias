#pragma once
#include "Topography.h"

class Hole :
    public Topography
{
private:
    const int id;
public:
    Hole();
    Hole(int id);
    ~Hole();
    int getId();
    bool canGo();
};

