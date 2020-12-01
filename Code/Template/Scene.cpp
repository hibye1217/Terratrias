#include "stdafx.h"
#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {
	for (auto& object : objectList) {
		SAFE_DELETE(object);
	}
	for (auto& ui : uiList) {
		SAFE_DELETE(ui);
	}
	for (auto& button : buttonList) {
		SAFE_DELETE(button);
	}
}

void Scene::Render() {
	
}

void Scene::Update(float dTime) {
	if (sceneManager->getOldSceneExist())
		sceneManager->deleteOldThings();

	// 만약 esc가 작동되었다면, 이하 루프문은 돌지 않기로 해야지
	//							= 씬을 업데이트 하지 않기로
	
	for (auto& object : objectList) {
		object->Update(dTime);
	}

	for (auto& ui : uiList) {
		ui->Update(dTime);
	}
}

void Scene::AddObject(Object* object) {
	objectList.push_back(object);
	object->setParent(nullptr);
}

void Scene::RemoveObject(Object* object) {
	objectList.remove(object);
}

void Scene::AddUI(Object* ui) {
	uiList.push_back(ui);
	ui->setParent(nullptr);
}

void Scene::RemoveUI(Object* ui) {
	uiList.remove(ui);
}