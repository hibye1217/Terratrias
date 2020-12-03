#include "stdafx.h"
#include "ClearScene.h"

ClearScene::ClearScene()
{

	float makeScale = ((float)SCREEN_HEIGHT / 6.0f) / (float)590;

	Button* next = new Button("Resources//Button/NextButton.png");

	//BFFinalize* BFF1;
	//BFF1 = new BFFinalize();
	//BFChangeScene* BFC1;
	//BFC1 = new BFChangeScene(new StageScene(save[0][0]+1));
	BFStage* BFn = new BFStage(save[0][0] + 1);

	next->setPos(100,100);
	next->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));

	buttonList.push_back(next);
	next->bfList.push_back(BFn);
	//next->bfList.push_back(BFC1);


	Button* restart = new Button("Resources//Button/RestartButton.png");
	//BFFinalize* BFF2;
	//BFF2 = new BFFinalize();
	//BFChangeScene* BFC2;
	//BFC2 = new BFChangeScene(new StageScene(save[0][0]));
	BFStage* BFr = new BFStage(save[0][0]);

	restart->setPos(100, 400);
	restart->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));

	buttonList.push_back(restart);
	//restart->bfList.push_back(BFF2);
	restart->bfList.push_back(BFr);


	Button* gotoMain = new Button("Resources//Button/QuitButton.png");
	BFFinalize* BFF3;
	BFF3 = new BFFinalize();
	BFChangeScene* BFC3;
	BFC3 = new BFChangeScene(new MainScene());

	gotoMain->setPos(100, 700);
	gotoMain->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));

	buttonList.push_back(gotoMain);
	gotoMain->bfList.push_back(BFF3);
	gotoMain->bfList.push_back(BFC3);

	for (int i = 0; i < 6; i++) {
		Sprite* spr;
		spr = new Sprite("Resources/FadeBackground.png");
		AddObject(spr);
		spr->setPos(0, 0);
	}

}

ClearScene::~ClearScene()
{
}

void ClearScene::Render()
{
	for (auto& p : objectList) {
		p->Render();
	}
}

void ClearScene::Update(float dTime)
{
	Scene::Update(dTime);
}
