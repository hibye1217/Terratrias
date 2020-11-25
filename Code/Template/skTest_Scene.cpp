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
	button->setPos(0, 0);	// ������� ��ǥ
	button->setDpos(100,100);
	button->bfList.push_back(new ButtonFunction());

	buttonList.push_back(button);



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
	AddObject(addingButton);

	// 4. ����
	addingButton->bfList.push_back(addingBF);
	buttonList.push_back(addingButton);

		//// BFChangeScene
	// 1. ��ư ��� ����
	BFChangeScene* changingBF;
	changingBF = new BFChangeScene(new MainScene());

	// 2. ��ư ����
	Button* changingButton;
	changingButton = new Button("Resources/UnitSquare.png");
	changingButton->setPos(0, 200);
	changingButton->setDpos(100, 100);
	AddObject(changingButton);

	// 3. ����
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

	// ��ư ��ü�� ȣ���� �˻絵 �ؾ���
	for (auto& button : buttonList)
		button->hoveringCheck(inputManager->GetMousePos());
}
