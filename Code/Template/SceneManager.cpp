#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	application = new Application();
	oldSceneExist = false;
	reservedChangeScene = false;

	currentScene = nullptr;
	for (int i = 1; i <= count; i++) {
		fade[i] = new Sprite("Resources/FadeBackground.png");
		fade[i]->setPos(0, 0);
		AddChild(fade[i]);
		show[i] = false;
	}
	timer = 0.0; idx = 0;
}

SceneManager::~SceneManager() {
	SAFE_DELETE(currentScene);
	for (auto& button : currentButtonList)
		SAFE_DELETE(button);
}

void SceneManager::Render() {
	currentScene->Render();

	for (auto& button : currentButtonList)
		button->Render();

	for (int i = 1; i <= count; i++) {
		if (show[i]) {
			fade[i]->Render();
		}
	}
}

void SceneManager::Update(float dTime) {

	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN)
		for (auto& button : currentButtonList)
			button->Check(inputManager->GetMousePos());
	for (auto& button : currentButtonList)
		button->hoveringCheck(inputManager->GetMousePos());
	//
	currentScene->Update(dTime);
	timer += dTime;
}

void SceneManager::ChangeScene() {
	oldScene = currentScene;
	oldSceneExist = true;
	ChangeButtonList(preparedScene);
	currentScene = preparedScene;
	reservedChangeScene = false;
}
void SceneManager::FadeChangeScene() {
	FadeIn();
	ChangeScene();
	FadeOut();
	
}

void SceneManager::FadeIn() {
	timer = 0.0; idx = 0;
	float tmp = application->getDeltaTime();
	while (idx < count) {
		timer += application->getDeltaTime();
		while (changeRate * idx < timer && idx < count) {
			idx += 1;
			show[idx] = true;
		}
		pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, BG_COLOR, 1.0f, 0);
		pd3dDevice->BeginScene();

		pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
		sceneManager->Render();
		pd3dSprite->End();

		pd3dDevice->EndScene();
		pd3dDevice->Present(0, 0, 0, 0);
	}
}

void SceneManager::FadeOut() {
	timer = 0.0; idx = 30;
	float tmp = application->getDeltaTime();
	while (idx > 0) {
		timer += application->getDeltaTime();
		while (changeRate * (count - idx) < timer && idx > 0) {
			show[idx] = false;
			idx -= 1;
		}
		pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, BG_COLOR, 1.0f, 0);
		pd3dDevice->BeginScene();

		pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
		sceneManager->Render();
		pd3dSprite->End();

		pd3dDevice->EndScene();
		pd3dDevice->Present(0, 0, 0, 0);
	}
}

void SceneManager::ChangeButtonList(Scene* myScene)
{
	currentButtonList.clear();
	for (auto& button : myScene->buttonList)
		currentButtonList.push_back((Button*)button);
}

void SceneManager::deleteOldThings()
{
	SAFE_DELETE(oldScene);
}

void SceneManager::setPreparedScene(Scene* scene)
{
	reservedChangeScene = true;
	preparedScene = scene;
}

bool SceneManager::getOldSceneExist()
{
	return oldSceneExist;
}

bool SceneManager::getReservedChangeScene()
{
	oldSceneExist = false;
	return reservedChangeScene;
}
