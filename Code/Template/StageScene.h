#pragma once
#include <string>
#include "BaseScene.h"

class StageScene :
    public BaseScene
{
private:
    User& user;
public:

    StageScene(int n);
    ~StageScene();

    void Render();
    void Update(float dTime);
};