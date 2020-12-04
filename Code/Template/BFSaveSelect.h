#pragma once
#include <fstream>
#include "ButtonFunction.h"
#include "MainScene.h"
class BFSaveSelect :
    public ButtonFunction
{
private:
    const char* filename;
    std::string name;
    std::fstream appendFileToWorkWith;
public:
    BFSaveSelect(int n);
    ~BFSaveSelect();

    void Do();
};

