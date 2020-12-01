#pragma once
#include "Scene.h"
#include "Button.h"
class SubScene :
    public Scene
{
public:
    SubScene();
    ~SubScene();

    void Render();
};

