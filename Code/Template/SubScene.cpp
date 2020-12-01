#include "stdafx.h"
#include "SubScene.h"

SubScene::SubScene() {

	for (int i = 0; i < 6; i++) {
		Sprite* spr;
		spr = new Sprite("Resources/FadeBackground.png");
		AddObject(spr);
		spr->setPos(0, 0);
	}
	// ��ư�� �˾Ƽ� ���߿� ����

	Button* button;
	button = new Button("Resources/UnitSquare.png");
	buttonList.push_back(button);
	button->setPos(100, 100);	// ������� ��ǥ
	button->setDpos(100, 100);
	button->bfList.push_back(new ButtonFunction());
}

SubScene::~SubScene()
{
	Scene::~Scene();
}

void SubScene::Render()
{
	for (auto& object : this->objectList)
		object->Render();

}
