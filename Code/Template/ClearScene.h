#pragma once
#include "Scene.h"
#include "BFChangeScene.h"
#include "BFFinalize.h"
#include "StageScene.h"
#include "MainScene.h"
#include "BFStage.h"

class ClearScene :
    public Scene
{
public:
	ClearScene(int n);
	~ClearScene();

	void Render();
	void Update(float dTime);
};

