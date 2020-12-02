#pragma once
#include <string>
#include "Const.h"
#include "Sprite.h"

class Topography
	: public Sprite	// 1
{
public:
	int type;
public:
	Topography();
	Topography(int type);
	Topography(int type, std::string path);
	virtual ~Topography();
	int getType();
	virtual bool canGo() = 0;
	virtual void onArrived();
	Topography& operator = (const Topography&) = default;
};
