#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene() {
	
	
	int h = (SCREEN_HEIGHT - 100) / 2;
	int w = (SCREEN_WIDTH - 1000) / 20;

	//setDpos(100,100);

	int access = save[0][0] + 1;

	// std::cout << "access" << ' ' << access << std::endl;

	BFStage* BF[20];
	BFExit* exit;

	for (int i = 1; i <= 10; i++) {
		BF[i] = new BFStage(i);
	}
	exit = new BFExit();

	/*BFStage* BF1;
	BF1 = new BFStage(1);
	BFStage* BF2;
	BF2 = new BFStage(2);
	BFStage* BF3;
	BF3 = new BFStage(3);
	BFStage* BF4;
	BF4 = new BFStage(4);
	BFStage* BF5;
	BF5 = new BFStage(5);
	BFStage* BF6;
	BF6 = new BFStage(6);
	BFStage* BF7;
	BF7 = new BFStage(7);
	BFStage* BF8;
	BF8 = new BFStage(8);
	BFStage* BF9;
	BF9 = new BFStage(9);
	BFStage* BF10;
	BF10 = new BFStage(10);*/


	// 2. 버튼 설정
	Button* button[20];
	Button* exitButton;

	for (int i = 1; i <= 10; i++) {
		if (access >= i) {
			if (save[i][1] != 0 && save[i][0] <= save[i][1]) {
				button[i] = new Button(stage_clear_path[i].c_str());
			}
			else {
				button[i] = new Button(stage_open_path[i].c_str());
			}
			button[i]->bfList.push_back(BF[i]);
		}
		else {
			button[i] = new Button(stage_close_path[i].c_str());
		}
	}
	exitButton = new Button("Resources/Button/Exit.png");
	exitButton->bfList.push_back(exit);

	/*Button* Button1;
	Button* Button2;
	Button* Button3;
	Button* Button4;
	Button* Button5;
	Button* Button6;
	Button* Button7;
	Button* Button8;
	Button* Button9;
	Button* Button10;
	if (access >= 1) {
		Button1 = new Button("Resources/LevelButton/Level1Open.png");
		Button1->bfList.push_back(BF1);
	}
	else {
		Button1 = new Button("Resources/LevelButton/Level1Close.png");
	}

	if (access >= 2) {
		Button2 = new Button("Resources/LevelButton/Level2Open.png");
		Button2->bfList.push_back(BF2);
	}
	else {
		Button2 = new Button("Resources/LevelButton/Level2Close.png");
	}

	if (access >= 3) {
		Button3 = new Button("Resources/LevelButton/Level3Open.png");
		Button3->bfList.push_back(BF3);
	}
	else {
		Button3 = new Button("Resources/LevelButton/Level3Close.png");
	}

	if (access >= 4) {
		Button4 = new Button("Resources/LevelButton/Level4Open.png");
		Button4->bfList.push_back(BF4);
	}
	else {
		Button4 = new Button("Resources/LevelButton/Level4Close.png");
	}

	if (access >= 5) {
		Button5 = new Button("Resources/LevelButton/Level5Open.png");
		Button5->bfList.push_back(BF5);
	}
	else {
		Button5 = new Button("Resources/LevelButton/Level5Close.png");
	}

	if (access >= 6) {
		Button6 = new Button("Resources/LevelButton/Level6Open.png");
		Button6->bfList.push_back(BF6);
	}
	else {
		Button6 = new Button("Resources/LevelButton/Level6Close.png");
	}

	if (access >= 7) {
		Button7 = new Button("Resources/LevelButton/Level7Open.png");
		Button7->bfList.push_back(BF7);
	}
	else {
		Button7 = new Button("Resources/LevelButton/Level7Close.png");
	}

	if (access >= 8) {
		Button8 = new Button("Resources/LevelButton/Level8Open.png");
		Button8->bfList.push_back(BF8);
	}
	else {
		Button8 = new Button("Resources/LevelButton/Level8Close.png");
	}

	if (access >= 9) {
		Button9 = new Button("Resources/LevelButton/Level9Open.png");
		Button9->bfList.push_back(BF9);
	}
	else {
		Button9 = new Button("Resources/LevelButton/Level9Close.png");
	}

	if (access >= 10) {
		Button10 = new Button("Resources/LevelButton/Level10Open.png");
		Button10->bfList.push_back(BF10);
	}
	else {
		Button10 = new Button("Resources/LevelButton/Level10Close.png");
	}*/

	for (int i = 1; i <= 10; i++) {
		button[i]->setPos(i * w + (100) * (i - 1), h);
		button[i]->setDpos(100, 100);
		buttonList.push_back(button[i]);
	}
	exitButton->setPos(11 * w + 1000, h);
	exitButton->setDpos(100, 100);
	buttonList.push_back(exitButton);

	/*Button1->setPos(w,h);
	Button1->setDpos(100, 100);
	Button1->bfList.push_back(BF1);
	buttonList.push_back(Button1);

	Button2->setPos(2*w + 100,h);
	Button2->setDpos(100, 100);
	buttonList.push_back(Button2);

	Button3->setPos(3*w+200,h);
	Button3->setDpos(100, 100);
	buttonList.push_back(Button3);

	Button4->setPos(4*w+300,h);
	Button4->setDpos(100, 100);
	buttonList.push_back(Button4);

	Button5->setPos(5*w+400,h);
	Button5->setDpos(100, 100);
	buttonList.push_back(Button5);

	Button6->setPos(6*w+500,h);
	Button6->setDpos(100, 100);
	buttonList.push_back(Button6);

	Button7->setPos(7*w+600,h);
	Button7->setDpos(100, 100);
	buttonList.push_back(Button7);

	Button8->setPos(8*w+700,h);
	Button8->setDpos(100, 100);
	buttonList.push_back(Button8);

	Button9->setPos(9*w+800,h);
	Button9->setDpos(100, 100);
	buttonList.push_back(Button9);

	Button10->setPos(10*w+900,h);
	Button10->setDpos(100, 100);
	buttonList.push_back(Button10);*/

}

MainScene::~MainScene() {

}

void MainScene::Render() {
	
}

void MainScene::Update(float dTime) {
	if(!sceneManager->getReservedChangeScene()) if (manager.getKeyCnt() != -1) manager.finalize();
	Scene::Update(dTime);

}