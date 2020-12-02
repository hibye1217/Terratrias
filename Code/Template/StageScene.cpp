#include "stdafx.h"
#include "StageScene.h"

StageScene::StageScene(int n) : user(manager.getUser())
{
	// ���� �������� ���� �ʱ�ȭ ����

	std::string stageName;

	stageName = "stage" + std::to_string(n);
	stageName += ".txt";

	manager.initialize(stageName.c_str());





	// ���� ���� ���������� �׸�ŭ ������ ��.
	// ���� Item�̶� topography�� Sprite�� ��ӹ���
	// �״ϱ� �ʱ�ȭ�Ҷ� sprite ���� ���ϰ�, �׳� �����ָ� ��

}

StageScene::~StageScene()
{

	// Topography�� Item ���������ϱ� finalize�� �׿� ���缭 �����ؾ��ҰŰ�����

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

	// �̻�������, manager.map[][]�� �ִ� ���� �ִ� Item�� Hole�� addObject���� ��������
	// Manager���� �ʱ�ȭ�� �����ϴµ�, �ű⼭ Scene�� addObejct�� �� ���� ����

	for (auto& object : this->objectList)
		object->Render();


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
