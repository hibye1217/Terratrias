#pragma once
#include "Scene.h"
#include "Button.h"
#include "BFStage.h"
class SubScene :
    public Scene
{
public:
    SubScene(int i);
    ~SubScene();
    void Render();
};

