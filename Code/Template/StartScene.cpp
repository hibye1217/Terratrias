#include "stdafx.h"
#include "StartScene.h"

StartScene::StartScene() : nextScene(nullptr)
{
	int w = (int)((SCREEN_WIDTH - 1122) / 2);
	int h = (int)((SCREEN_HEIGHT - 649) / 2);
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

void StartScene::setNextScene(Scene* myScene)
{
	nextScene = myScene;
	sceneManager->setPreparedScene(nextScene);
}

void StartScene::Render()
{
	for (auto& ob : objectList) {
		ob->Render();
	}
}

void StartScene::Update(float dTime)
{
	//Scene::Update(dTime);

	//for (int i = 0; i < 256; i++) {
		//if (inputManager->GetKeyState(i) == KEY_DOWN) {
		if(inputManager->GetKeyState(' ')){
			//std::cout << i << std::endl;
			sceneManager->setPreparedScene(nextScene);
			//break;
		}
	//}
}
