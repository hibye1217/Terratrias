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

    BaseScene(int i);
    ~BaseScene();

    void Render();
    void setIsSubSceneOn();
    void Update(float dTime);

};

