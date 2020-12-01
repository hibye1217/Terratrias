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
	if (isSubSceneOn)			// �̰� �� �Ʒ��� �־����. ��, BaseScene�� ��� �޴� �ֵ��� �� �����ϰ� BaseScene::Render()�� �������� ȣ���ؾ���
		subScene->Render();
}

void BaseScene::Update(float dTime) {


	if (sceneManager->getOldSceneExist())
		sceneManager->deleteOldThings();
	
	// esc �� ���ȴٸ�
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