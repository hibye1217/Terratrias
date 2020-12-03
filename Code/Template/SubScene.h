#pragma once
#include "Scene.h"
#include "Button.h"
class SubScene :
    public Scene
{
public:
    SubScene(int i);
    ~SubScene();
    void Render();
};

