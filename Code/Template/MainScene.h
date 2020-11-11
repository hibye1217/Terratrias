#pragma once

#include "Font.h"
#include "Scene.h"
#include "Sprite.h"

class MainScene : public Scene {
public:
	MainScene();
	~MainScene();

	void Render();
	void Update(float dTime);
};
