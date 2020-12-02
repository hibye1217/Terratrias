#include "stdafx.h"
#include "StageScene.h"

StageScene::StageScene(int n) : user(manager.getUser())
{
	// 파일 가져오고 게임 초기화 진행

	std::string stageName;

	stageName = "stage" + std::to_string(n);
	stageName += ".txt";

	manager.initialize(stageName.c_str());





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
			manager.getCell(i, j).getTopography()->Render();
			manager.getCell(i, j).getItem()->Render();
		}
	}

	manager.getUser().Render();

	// 이상하지만, manager.map[][]에 있는 셀에 있는 Item과 Hole은 addObject하지 않을거임
	// Manager에서 초기화를 진행하는데, 거기서 Scene의 addObejct를 할 수가 없음

	for (auto& object : this->objectList)
		object->Render();


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


	}
}
