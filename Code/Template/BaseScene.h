#pragma once
#include "Scene.h"
#include "SubScene.h"
class BaseScene :
    public Scene
{
protected:
    bool isSubSceneOn;
public:
    SubScene *subScene;

    BaseScene();
    ~BaseScene();

    void Render();
    void Update(float dTime);

};
