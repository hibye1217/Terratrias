#pragma once
#include <string>
#include "Const.h"

class Topography : public Sprite
{
public:
	int type;
public:
	Topography();
	Topography(int type);
	virtual ~Topography();
	int getType();
	virtual bool canGo() = 0;
	virtual void onArrived();
	Topography& operator = (const Topography&) = default;
};
