#include "stdafx.h"
#include "StartScene.h"

StartScene::StartScene()
{
	int w = (SCREEN_WIDTH - 649) / 2;
	int h = (SCREEN_HEIGHT - 1122) / 2;
	Sprite* logo = new Sprite("Resources/Button/Logo.png");
	logo->setPos(w, h);
	AddObject(logo);
}

StartScene::~StartScene()
{
	for (auto& ob : objectList) {
		SAFE_DELETE(ob);
	}
}

void StartScene::Render()
{
	for (auto& ob : objectList) {
		ob->Render();
	}
}

void StartScene::Update(float dTime)
{
	Scene::Update(dTime);
}
