#pragma once

#include "Object.h"

class Scene {
protected:
	std::list<Object*> objectList;
	std::list<Object*> uiList;

public:
	std::list<Object*> buttonList;

	Scene();
	~Scene();

	virtual void Render();
	virtual void Update(float dTime);

	void AddObject(Object* object);
	void RemoveObject(Object* object);

	void AddUI(Object* ui);
	void RemoveUI(Object* ui);
};