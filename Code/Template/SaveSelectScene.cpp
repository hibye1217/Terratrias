#include "stdafx.h"
#include "SaveSelectScene.h"
#include "MainScene.h"

SaveSelectScene::SaveSelectScene()
{

	int makeScale = (int)(SCREEN_HEIGHT / 4) / 590;
	int leftMargin = (SCREEN_WIDTH - (1476 * makeScale));

	BFSaveSelect* BFSS1 = new BFSaveSelect(1);
	BFSaveSelect* BFSS2 = new BFSaveSelect(2);
	BFSaveSelect* BFSS3 = new BFSaveSelect(3);

	BFChangeScene* BFCS1 = new BFChangeScene(new MainScene());
	BFChangeScene* BFCS2 = new BFChangeScene(new MainScene());
	BFChangeScene* BFCS3 = new BFChangeScene(new MainScene());


	Button *SButton1 = new Button("Resources/Button/SaveFile.png");
	Button *SButton2 = new Button("Resources/Button/SaveFile.png");
	Button *SButton3 = new Button("Resources/Button/SaveFile.png");

	SButton1->setPos(leftMargin, (int)(147.5 * makeScale));
	SButton2->setPos(leftMargin, (int)(295 * makeScale));
	SButton3->setPos(leftMargin, (int)(442.5 * makeScale));

	SButton1->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));
	SButton2->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));
	SButton3->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));

	buttonList.push_back(SButton1);
	buttonList.push_back(SButton2);
	buttonList.push_back(SButton3);

	SButton1->bfList.push_back(BFSS1);
	SButton2->bfList.push_back(BFSS2);
	SButton3->bfList.push_back(BFSS3);

	SButton1->bfList.push_back(BFCS1);
	SButton2->bfList.push_back(BFCS2);
	SButton3->bfList.push_back(BFCS3);
}

SaveSelectScene::~SaveSelectScene()
{
}

void SaveSelectScene::Render()
{
	for (auto& ob : objectList) {
		ob->Render();
	}
}
