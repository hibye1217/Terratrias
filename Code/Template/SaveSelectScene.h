#pragma once
#include "Scene.h"
#include "Button.h"
#include "BFAdDelSprite.h"
#include "BFChangeScene.h"
#include "BFSaveSelect.h"


class SaveSelectScene :
    public Scene
{
public:
    SaveSelectScene();
    ~SaveSelectScene();

    void Render();
    void Update(float dTime);
};

