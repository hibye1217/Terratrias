#include "stdafx.h"
#include "StageScene.h"

StageScene::StageScene(int n) : user(manager.getUser())
{
	// 파일 가져오고 게임 초기화 진행

	std::string stageName;

	stageName = "stage" + std::to_string(n);
	stageName += ".txt";

	manager.initialize(stageName);


	// 이제 마진 정해졌으니 그만큼 넣으면 됨.
	// 이제 Item이랑 topography가 Sprite를 상속받음
	// 그니까 초기화할때 sprite 쓸거 정하고, 그냥 보여주면 됨

}

StageScene::~StageScene()
{

	// Topography랑 Item 수정했으니까 finalize도 그에 맞춰서 수정해야할거같은데

	manager.finalize();
}

void StageScene::Render()
{
	for (int i = 0; i < manager.getHeight(); ++i) {
		for (int j = 0; j < manager.getWidth(); ++j) {
			//map[i][j].setItem(new Jump());
			//map[i][j].setTopography(new Space());
			manager.getCell(i, j).setItem(new Jump());
			manager.getCell(i, j).setTopography(new Space());
		}
	}

	int margin_1 = user.getMargin1();
	int margin_2 = user.getMargin2();
	//user.getSprite()->setPos(margin_2 + (user.getY() * i_hat), margin_1 + (user.getY() * j_hat));
	for (int i = 0; i < manager.getHeight(); ++i) {
		for (int j = 0; j < manager.getWidth(); ++j) {
			Topography* a = manager.getCell(i, j).getTopography();
			manager.getCell(i,j).getTopography()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));
			manager.getCell(i,j).getTopography()->getSprite()->setScale(manager.getScaleRatio(), manager.getScaleRatio());
			a->Render();	// 1
			Item* b = manager.getCell(i, j).getItem();
			manager.getCell(i, j).getItem()->getSprite()->setPos(margin_2 + (i_hat * j), margin_1 + (j_hat * i));
			manager.getCell(i, j).getItem()->getSprite()->setScale(manager.getScaleRatio(), manager.getScaleRatio());
			b->Render();		// 2
		}
	}

	manager.getUser().getSprite()->Render();								// 3

	// 이상하지만, manager.map[][]에 있는 셀에 있는 Item과 Hole은 addObject하지 않을거임
	// Manager에서 초기화를 진행하는데, 거기서 Scene의 addObejct를 할 수가 없음

	for (auto& object : this->objectList)
		object->Render();

	// User.h
		// 1
	// User.cpp
		// 1, 2
	// Item.h
		// 1
	// Item.cpp
		// 1, 2
	// Topography.h
		// 1
	// Topograhpy.cpp
		// 1, 2
	// manager.cpp
		// 1, 2, 3
	// StageScene.cpp
		// 1, 2, 3

	// 얘 위에 다 있어야해
	BaseScene::Render();
}

void StageScene::Update(float dTime)
{
	BaseScene::Update(dTime);
	// 얘 아래에 있어야해


	if (isSubSceneOn) {
		// 딱히 할게 있나?
	}
	else {
		// 준서가 루프 짤 부분
		if (inputManager->GetKeyState('W') == KEY_DOWN || inputManager->GetKeyState('w') == KEY_DOWN)
		{
			user.move(Enum::UP);
		}
		else if (inputManager->GetKeyState('A') == KEY_DOWN || inputManager->GetKeyState('a') == KEY_DOWN)
		{
			user.move(Enum::LEFT);
		}
		else if (inputManager->GetKeyState('S') == KEY_DOWN || inputManager->GetKeyState('s') == KEY_DOWN)
		{
			user.move(Enum::DOWN);
		}
		else if (inputManager->GetKeyState('D') == KEY_DOWN || inputManager->GetKeyState('d') == KEY_DOWN)
		{
			user.move(Enum::RIGHT);
		}
		else if (inputManager->GetKeyState(' ') == KEY_DOWN)
		{
			user.useItem();
		}
		else if (inputManager->GetKeyState('Q') == KEY_DOWN || inputManager->GetKeyState('q') == KEY_DOWN)
		{
			user.gainItem();
		}
		else if (inputManager->GetKeyState('E') == KEY_DOWN || inputManager->GetKeyState('e') == KEY_DOWN)
		{
			user.putItem();
		}
	}
}

