#pragma once

#include "Font.h"
#include "Scene.h"
#include "Sprite.h"
#include "BFChangeScene.h"
#include "StageScene.h"
#include "BFStage.h"
#include "BFExit.h"

class MainScene : public Scene {
public:
	MainScene();
	~MainScene();

	void Render();
	void Update(float dTime);
};
