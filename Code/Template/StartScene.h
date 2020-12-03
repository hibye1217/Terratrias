#pragma once
#include "Scene.h"
class StartScene :
    public Scene
{
private:
    Scene* nextScene;
public:
    StartScene();
    ~StartScene();

    void setNextScene(Scene*);

    void Render();
    void Update(float dTime);
};

