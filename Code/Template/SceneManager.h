#pragma once

#include "Scene.h"
#include "Object.h"
#include "Sprite.h"
#include "Button.h"
#include "Application.h"

class SceneManager : public Object {
private:
	Application* application;
	Scene* oldScene;
	Scene* currentScene;
	Scene* preparedScene;
	std::list<Button*> currentButtonList;
	
	const int count = 30;
	const float changeRate = 1.0 / 30;
	Sprite* fade[40];
	bool oldSceneExist;
	bool reservedChangeScene;
	bool show[40];
	int idx;
	float timer;

public:
	SceneManager();
	~SceneManager();

	void Render();
	void Update(float dTime);


	void ChangeScene();
	void FadeChangeScene();

	void FadeIn();
	void FadeOut();

	void ChangeButtonList(Scene*);

	void deleteOldThings();
	void setPreparedScene(Scene*);

	bool getOldSceneExist();
	bool getReservedChangeScene();
};