#include "stdafx.h"
#include "jkTest_Scene.h"

jkTest_Scene::jkTest_Scene() {
	sprite1 = new Sprite("Resources/Danmaku_1.png");
	sprite1->setPos(50, 50);
	AddObject(sprite1);

	for (int i = 1; i <= count; i++) {
		fb[i] = new FadeBackground();
		fb[i]->setPos(0, 0);
		show[i] = false;
		AddObject(fb[i]);
	}

	sprite2 = new Sprite("Resources/Danmaku_1.png");
	sprite2->setPos(100, 50);
	AddObject(sprite2);
}

jkTest_Scene::~jkTest_Scene() {

}

void jkTest_Scene::Update(float dTime) {
	timer += dTime;
	
	while (fps * idx < timer && idx < count) {
		idx += 1;
		show[idx] = true;
	}
}

void jkTest_Scene::Render() {
	sprite1->Render();

	for (int i = 1; i <= count; i++) {
		if (show[i]) {
			fb[i]->Render();
		}
	}

	sprite2->Render();
}