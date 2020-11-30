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
	std::list<Button*> oldButtonList;
	std::list<Button*> buttonList;
	std::list<Button*> preparedButtonList;
	
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

	void AppendButtonList(Button*);
	void ChangeButtonList();

	void deleteOldThings();
	void setPreparedScene(Scene* scene);

	bool getOldSceneExist();
	bool getReservedChangeScene();
};