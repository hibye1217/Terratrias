#include "stdafx.h"
#include "skTest_Scene.h"


skTest_Scene::skTest_Scene()
{
	spr = new Sprite("Resources/Danmaku_1.png");
	AddObject(spr);
	spr->setPos(200, 200);
	
	button = new Button("Resources/UnitSquare.png");
	AddObject(button);
	button->setPos(0, 0);	// ÁÂÃø»ó´Ü ÁÂÇ¥
}

skTest_Scene::~skTest_Scene()
{
}

void skTest_Scene::Render()
{
	spr->Render();
	button->Render();
}

void skTest_Scene::Update(float dTime)
{
	Scene::Update(dTime);
	
}
