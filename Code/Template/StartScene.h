#pragma once
#include "Scene.h"
class StartScene :
    public Scene
{
public:
    StartScene();
    ~StartScene();

    void Render();
    void Update(float dTime);
};

