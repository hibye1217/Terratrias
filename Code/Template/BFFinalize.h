#pragma once
#include "stdafx.h"
#include "ButtonFunction.h"
class BFFinalize :
    public ButtonFunction
{
public:
    BFFinalize();    // ButtonFunction 중, Scene 교체 기능
    ~BFFinalize();               // 소멸자에서 씬 파괴하면 겜 터지겠지

    void Do();
};

