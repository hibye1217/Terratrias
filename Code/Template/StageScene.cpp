#include "stdafx.h"
#include "StageScene.h"

StageScene::StageScene(int n)
{
	// ���� �������� ���� �ʱ�ȭ ����

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

	// ���� ���� ���������� �׸�ŭ ������ ��.
	// ������ ���� ����. map�� �����ϱ� �׿� �ش��ϴ� object�� ���� map1�� �־���ϴµ�, ��ĳ �����Ҳ���?

}

StageScene::~StageScene()
{
	manager.finalize();
}

void StageScene::Render()
{

	// �� ���� �� �־����
	BaseScene::Render();
}

void StageScene::Update(float dTime)
{
	BaseScene::Update(dTime);
	// �� �Ʒ��� �־����


	if (isSubSceneOn) {
		// ���� �Ұ� �ֳ�?
	}
	else {
		// �ؼ��� ���� © �κ�


	}
}
