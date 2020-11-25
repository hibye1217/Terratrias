#include "stdafx.h"
#include "skTest_Scene.h"


skTest_Scene::skTest_Scene()
{
	spr = new Sprite("Resources/Danmaku_1.png");
	AddObject(spr);
	spr->setPos(200, 200);
	
	Button* button;

	button = new Button("Resources/UnitSquare.png");
	AddObject(button);
	button->setPos(0, 0);	// 좌측상단 좌표
	button->setDpos(100,100);
	button->bfList.push_back(new ButtonFunction());

	buttonList.push_back(button);



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
	AddObject(addingButton);

	// 4. 연결
	addingButton->bfList.push_back(addingBF);
	buttonList.push_back(addingButton);

		//// BFChangeScene
	// 1. 버튼 기능 설정
	BFChangeScene* changingBF;
	changingBF = new BFChangeScene(new MainScene());

	// 2. 버튼 설정
	Button* changingButton;
	changingButton = new Button("Resources/UnitSquare.png");
	changingButton->setPos(0, 200);
	changingButton->setDpos(100, 100);
	AddObject(changingButton);

	// 3. 연결
	changingButton->bfList.push_back(changingBF);
	buttonList.push_back(changingButton);

	Object Item;


	std::cout << J_HAT << std::endl;
}

skTest_Scene::~skTest_Scene()
{
	for (auto& button : buttonList) {
		SAFE_DELETE(button);
	}
	
	SAFE_DELETE(Sun);
	SAFE_DELETE(spr);
}

void skTest_Scene::Render()
{
	for (auto& object : this->objectList)
		object->Render();

	// button->Render();
}

void skTest_Scene::Update(float dTime)
{
	Scene::Update(dTime);
	
	if (inputManager->GetKeyState(VK_LBUTTON) == KEY_DOWN) 
		for (auto& button : buttonList)
			button->Check(inputManager->GetMousePos());

	// 버튼 자체의 호버링 검사도 해야함
	for (auto& button : buttonList)
		button->hoveringCheck(inputManager->GetMousePos());
}
