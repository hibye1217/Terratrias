#pragma once
#include "Scene.h"
#include "Object.h"
#include "Sprite.h"
#include "Button.h"

class skTest_Scene :
    public Scene
{
public:
	Sprite* spr;
	Button* button;

	std::list<Button*> buttonList;

	skTest_Scene();
	~skTest_Scene();

	void Render();
	void Update(float dTime);
};

