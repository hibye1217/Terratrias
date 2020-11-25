#pragma once

#include "Scene.h"
#include "Object.h"
#include "Sprite.h"
#include "Button.h"
#include "Application.h"

class SceneManager : public Object {
private:
	Application* application;
	Scene* currentScene;
	std::list<Button*> buttonList;
	
	const int count = 30;
	const float changeRate = 1.0 / 30;
	Sprite* fade[40];
	bool show[40];
	int idx;
	float timer;

public:
	SceneManager();
	~SceneManager();

	void Render();
	void Update(float dTime);

	void ChangeScene(Scene* scene);
	void FadeChangeScene(Scene* scene);

	void FadeIn();
	void FadeOut();

	void AppendButtonList(Button*);
	void ClearButtonList();
};