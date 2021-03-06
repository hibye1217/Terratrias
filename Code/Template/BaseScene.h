#pragma once
#include "Scene.h"

class SubScene;

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

