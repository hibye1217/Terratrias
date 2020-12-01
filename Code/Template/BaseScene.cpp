#include "stdafx.h"
#include "BaseScene.h"

BaseScene::BaseScene()
{
	subScene = new SubScene();
	isSubSceneOn = false;
}

BaseScene::~BaseScene()
{
	SAFE_DELETE(subScene);
	Scene::~Scene();
}

void BaseScene::Render()
{
	if (isSubSceneOn)			// 이게 맨 아래에 있어야함. 즉, BaseScene을 상속 받는 애들은 다 렌더하고 BaseScene::Render()를 마지막에 호출해야함
		subScene->Render();
}

void BaseScene::Update(float dTime) {


	if (sceneManager->getOldSceneExist())
		sceneManager->deleteOldThings();
	
	// esc 가 눌렸다면
	if (inputManager->GetKeyState(27) == KEY_DOWN) {
		if (isSubSceneOn) 
			sceneManager->ChangeButtonList(this);
		else 
			sceneManager->ChangeButtonList(subScene);
		isSubSceneOn = !isSubSceneOn;

	}

	for (auto& object : objectList) 
			object->Update(dTime);

	for (auto& ui : uiList) 
			ui->Update(dTime);
}