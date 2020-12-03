#include "stdafx.h"
#include "BFChangeScene.h"
#include "StageScene.h"
#include "SubScene.h"
#include "MainScene.h"
#include "BFFinalize.h"

SubScene::SubScene(int i) {

	for (int i = 0; i < 6; i++) {
		Sprite* spr;
		spr = new Sprite("Resources/FadeBackground.png");
		AddObject(spr);
		spr->setPos(0, 0);
	}
	// 버튼은 알아서 나중에 정함


	float makeScale = ((float)SCREEN_HEIGHT / 6.0f) / (float)590;

	Button* changingButton;
	changingButton = new Button("Resources/Button/RestartButton.png");
	buttonList.push_back(changingButton);
	changingButton->setPos(100, 100);	// 좌측상단 좌표
	changingButton->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));
	
	//BFFinalize* BFFA;
	//BFFA = new BFFinalize();
	//BFChangeScene* changingBF;
	//changingBF = new BFChangeScene(new StageScene(i));
	BFStage* BF = new BFStage(i);

	buttonList.push_back(changingButton);
	changingButton->bfList.push_back(BF);
	//changingButton->bfList.push_back(BFFA);



	BFFinalize* BFF;
	BFF = new BFFinalize();
	BFChangeScene* BFmain;
	BFmain = new BFChangeScene(new MainScene());

	// 2. 버튼 설정
	Button* gotoMain;
	gotoMain = new Button("Resources/Button/QuitButton.png");
	gotoMain->setPos(100, 500);
	changingButton->setDpos((int)(1476 * makeScale), (int)(590 * makeScale));

	// 3. 연결
	buttonList.push_back(gotoMain);
	changingButton->bfList.push_back(BFmain);
	changingButton->bfList.push_back(BFF);


}

SubScene::~SubScene()
{
	Scene::~Scene();
}

void SubScene::Render()
{
	for (auto& object : this->objectList)
		object->Render();

}
