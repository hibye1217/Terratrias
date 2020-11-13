#pragma once
#include "ButtonFunction.h"

class BFChangeScene :
    public ButtonFunction
{
public:
    Scene* scene;

    BFChangeScene(Scene* scene);    // ButtonFunction 중, Scene 교체 기능
    ~BFChangeScene();

    void Do();
};

