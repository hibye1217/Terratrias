#pragma once
#include "ButtonFunction.h"
#include "BaseScene.h"
class BFResume :
    public ButtonFunction
{
public:
    BaseScene* scene;

    BFResume(BaseScene* scene);    // ButtonFunction 중, Scene 교체 기능
    ~BFResume();               // 소멸자에서 씬 파괴하면 겜 터지겠지

    void Do();
};

