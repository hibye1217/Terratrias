#pragma once
#include "ButtonFunction.h"
#include "StageScene.h"
class BFStage :
    public ButtonFunction
{
private:
    int n;
public:
    BFStage(int);
    ~BFStage();

    void Do();
};

