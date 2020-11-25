#include "stdafx.h"
#include "SceneManager.h"

SceneManager::SceneManager() {
	application = new Application();

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
	for (auto& button : buttonList)
		SAFE_DELETE(button);
}

void SceneManager::Render() {
	currentScene->Render();

	for (int i = 1; i <= count; i++) {
		//std::cout << show[i] << ' ';
		if (show[i]) {
			fade[i]->Render();
		}
	}
	//std::cout << std::endl;
}

void SceneManager::Update(float dTime) {
	// 여따 버튼 확인 넣을까?
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN)
		for (auto& button : buttonList)
			button->Check(inputManager->GetMousePos());
	for (auto& button : buttonList)
		button->hoveringCheck(inputManager->GetMousePos());

	currentScene->Update(dTime);
	timer += dTime;
}

void SceneManager::ChangeScene(Scene* scene) {
	SAFE_DELETE(currentScene);
	currentScene = scene;
}

void SceneManager::FadeChangeScene(Scene* scene) {
	FadeIn();
	SAFE_DELETE(currentScene);
	currentScene = scene;
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

void SceneManager::AppendButtonList(Button* button)
{
	buttonList.push_back(button);
}

void SceneManager::ClearButtonList()
{
	for (auto& button : buttonList)
		SAFE_DELETE(button);
}
