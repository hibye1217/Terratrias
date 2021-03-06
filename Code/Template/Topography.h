#pragma once
#include <string>
#include "Const.h"
#include "Sprite.h"

class Topography
//	: public Sprite	// 1
{
public:
	int type;
	Sprite* sprite;
public:
	Topography();
	Topography(int type);
	Topography(int type, int id);
	virtual ~Topography();
	int getType();
	void setSprite(Sprite*);
	Sprite* getSprite();
	void Render();
	virtual bool canGo() = 0;
	virtual void onArrived();
};
