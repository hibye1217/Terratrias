#pragma once
#include "Scene.h"
#include "SubScene.h"
class BaseScene :
    public Scene
{
private:
    bool isSubSceneOn;
public:
    SubScene *subScene;

    BaseScene();
    ~BaseScene();

    void Render();
    void Update(float dTime);

};

