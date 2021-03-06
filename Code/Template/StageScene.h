#pragma once
#include <string>
#include "BaseScene.h"
#include "ClearScene.h"

class StageScene :
    public BaseScene
{
private:
    User& user;
    int stage;
public:

    StageScene(int n);
    ~StageScene();

    void Render();
    void Update(float dTime);
};