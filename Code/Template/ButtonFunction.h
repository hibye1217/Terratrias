#pragma once
#include "Scene.h"

class ButtonFunction
{
public:

	ButtonFunction();	// ButtonFunction은 체계적으로 분류된 Button의 기능들이다
	~ButtonFunction();

	virtual void Do();
};

