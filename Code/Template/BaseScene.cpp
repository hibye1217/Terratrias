#include "stdafx.h"
#include "BaseScene.h"
#include "BFResume.h"

BaseScene::BaseScene()
{
	subScene = new SubScene(this);
	isSubSceneOn = false;

	BFResume* BFr = new BFResume(this);
}

BaseScene::~BaseScene()
{
	SAFE_DELETE(subScene);

}

void BaseScene::Render()
{
	if (isSubSceneOn)			// �̰� �� �Ʒ��� �־����. ��, BaseScene�� ��� �޴� �ֵ��� �� �����ϰ� BaseScene::Render()�� �������� ȣ���ؾ���
		subScene->Render();
}

void BaseScene::setIsSubSceneOn()
{
	isSubSceneOn = !isSubSceneOn;
}

void BaseScene::Update(float dTime) {


	if (sceneManager->getOldSceneExist())
		sceneManager->deleteOldThings();
	
	// esc �� ���ȴٸ�
	if (inputManager->GetKeyState(27) == KEY_DOWN) {
		if (isSubSceneOn) {
			sceneManager->ChangeButtonList(this);
		}
		else {
			sceneManager->ChangeButtonList(subScene);
		}
		isSubSceneOn = !isSubSceneOn;
	}


	/// �����¿�
	/// �����ۻ��


	for (auto& object : objectList) 
			object->Update(dTime);

	for (auto& ui : uiList) 
			ui->Update(dTime);
}