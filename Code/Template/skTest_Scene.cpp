#include "stdafx.h"
#include "skTest_Scene.h"
#include "StageScene.h"


skTest_Scene::skTest_Scene()
{
	spr = new Sprite("Resources/Danmaku_1.png");
	AddObject(spr);
	spr->setPos(200, 200);
	
	// ��ĳ ������ �𸣴� soundManager��
	// soundManager->LoadWaveFile("Resources/test.wav", "test");
	// soundManager->PlayWaveFile("test");


	Button* button;
	button = new Button("Resources/UnitSquare.png");
	buttonList.push_back(button);
	button->setPos(0, 0);	// ������� ��ǥ
	button->setDpos(100, 100);
	button->bfList.push_back(new ButtonFunction());

		//// BFAdDelSprite
	// 1. ������Ʈ ����
	Sun = new Sprite("Resources/Dark_Sun.png");
	Sun->setPos(500, 0);

	// 2. ��ư��� ����
	BFAdDelSprite* addingBF;
	addingBF = new BFAdDelSprite(this->objectList, Sun);

	// 3. ��ư ����
	Button* addingButton;
	addingButton = new Button("Resources/UnitSquare.png");
	addingButton->setPos(0, 100);
	addingButton->setDpos(100, 100);

	// 4. ����
	buttonList.push_back(addingButton);
	addingButton->bfList.push_back(addingBF);

		//// BFChangeScene
	// 1. ��ư ��� ����
	BFChangeScene* changingBF;
	changingBF = new BFChangeScene(new BaseScene());

	// 2. ��ư ����
	Button* changingButton;
	changingButton = new Button("Resources/UnitSquare.png");
	changingButton->setPos(0, 200);
	changingButton->setDpos(100, 100);

	// 3. ����
	buttonList.push_back(changingButton);
	changingButton->bfList.push_back(changingBF);
}

skTest_Scene::~skTest_Scene()
{
	Scene::~Scene();
}

void skTest_Scene::Render()
{
	for (auto& object : this->objectList)
		object->Render();

}

void skTest_Scene::Update(float dTime)
{
	Scene::Update(dTime);
}
