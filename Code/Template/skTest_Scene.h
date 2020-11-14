#pragma once
#include "Scene.h"
#include "Object.h"
#include "Sprite.h"
#include "Button.h"
#include "BFAdDelSprite.h"
#include "BFChangeScene.h"
#include "MainScene.h"

class skTest_Scene :
    public Scene
{
public:
	Sprite* spr;
	Sprite* Sun;

	std::list<Button*> buttonList;

	skTest_Scene();
	~skTest_Scene();

	void Render();
	void Update(float dTime);
};

