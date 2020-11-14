#pragma once
#include "Scene.h"
#include "FadeBackground.h"

class jkTest_Scene : public Scene {
private:
	Sprite* sprite1;
	Sprite* sprite2;
	int count = 30;
	FadeBackground* fb[70];
	bool show[40];
	float timer = 0.0;
	float fps = 1.0 / count;
	int idx = 0;
	
public:
	jkTest_Scene();
	~jkTest_Scene();

	void Update(float dTime);
	void Render();
};