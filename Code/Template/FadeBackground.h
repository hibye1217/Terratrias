#pragma once
#include "Object.h"
#include "Sprite.h"

class FadeBackground : public Object {
private:
	Sprite* sprite;

public:
	FadeBackground();
	~FadeBackground();

	void Update(float dTime);
	void Render();
};