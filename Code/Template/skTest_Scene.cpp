#include "stdafx.h"
#include "skTest_Scene.h"
#include "StageScene.h"


skTest_Scene::skTest_Scene()
{
	spr = new Sprite("Resources/Danmaku_1.png");
	AddObject(spr);
	spr->setPos(200, 200);
	
	// 어캐 쓰는지 모르는 soundManager임
	// soundManager->LoadWaveFile("Resources/test.wav", "test");
	// soundManager->PlayWaveFile("test");


	Button* button;
	button = new Button("Resources/UnitSquare.png");
	buttonList.push_back(button);
	button->setPos(0, 0);	// 좌측상단 좌표
	button->setDpos(100, 100);
	button->bfList.push_back(new ButtonFunction());

		//// BFAdDelSprite
	// 1. 오브젝트 설정
	Sun = new Sprite("Resources/Dark_Sun.png");
	Sun->setPos(500, 0);

	// 2. 버튼기능 설정
	BFAdDelSprite* addingBF;
	addingBF = new BFAdDelSprite(this->objectList, Sun);

	// 3. 버튼 설정
	Button* addingButton;
	addingButton = new Button("Resources/UnitSquare.png");
	addingButton->setPos(0, 100);
	addingButton->setDpos(100, 100);

	// 4. 연결
	buttonList.push_back(addingButton);
	addingButton->bfList.push_back(addingBF);

		//// BFChangeScene
	// 1. 버튼 기능 설정
	BFChangeScene* changingBF;
	changingBF = new BFChangeScene(new BaseScene());

	// 2. 버튼 설정
	Button* changingButton;
	changingButton = new Button("Resources/UnitSquare.png");
	changingButton->setPos(0, 200);
	changingButton->setDpos(100, 100);

	// 3. 연결
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
