#pragma once
#include "ButtonFunction.h"

class BFChangeScene :
    public ButtonFunction
{
public:
    Scene* scene;

    BFChangeScene(Scene* scene);    // ButtonFunction 중, Scene 교체 기능
    ~BFChangeScene();               // 소멸자에서 씬 파괴하면 겜 터지겠지

    void Do();
};

