#include "stdafx.h"
#include "StageScene.h"

StageScene::StageScene(int n)
{
	// 파일 가져오고 게임 초기화 진행

	std::string stageName;

	stageName = "stage" + std::to_string(n);
	stageName += ".txt";

	manager.initialize(stageName);


	int grid_height = manager.getHeight();
	int grid_width = manager.getWidth();

	int margin_1 = min((SCREEN_HEIGHT - (SCREEN_HEIGHT % grid_height)) / grid_height, 50);
	int margin_2 = min((SCREEN_WIDTH - (SCREEN_WIDTH % grid_width)) / grid_width, 50);

	i_hat = margin_1 < margin_2 ? margin_1 : margin_2;
	j_hat = i_hat;

	margin_bafor = j_hat * grid_height / 2;
	margin_side = i_hat * grid_width / 2;

	// 이제 마진 정해졌으니 그만큼 넣으면 됨.
	// 문제는 따로 있지. map이 있으니까 그에 해당하는 object를 넣은 map1도 있어야하는데, 어캐 관리할꺼임?

}

StageScene::~StageScene()
{
	manager.finalize();
}

void StageScene::Render()
{

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
