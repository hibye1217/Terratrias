#pragma once
#include "Scene.h"
#include "BFChangeScene.h"
#include "BFFinalize.h"

class ClearScene :
    public Scene
{
public:
	ClearScene();
	~ClearScene();

	void Render();
	void Update(float dTime);
};

