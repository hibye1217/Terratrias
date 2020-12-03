#include "stdafx.h"
#include "ClearScene.h"

ClearScene::ClearScene()
{
	Button* next = new Button("Resources//Button/NextButton.png");

	Button* restart = new Button("Resources//Button/RestartButton.png");

	Button* gotoMain = new Button("Resources//Button/QuitButton.png");

}

ClearScene::~ClearScene()
{
}

void ClearScene::Render()
{
	for (auto& p : objectList) {
		p->Render();
	}
}

void ClearScene::Update(float dTime)
{
	Scene::Update(dTime);
}
