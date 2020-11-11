#pragma once
#include "Scene.h"
#include "Object.h"
#include "Sprite.h"

class skTest_Scene :
    public Scene
{
public:
	Sprite* spr;

	skTest_Scene();
	~skTest_Scene();

	void Render();
	void Update(float dTime);
};

