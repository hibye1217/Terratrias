#include "stdafx.h"
#include "Button.h"

Button::Button() : Sprite("Resources/Danmaku_1.png") {}

Button::Button(const char* path) : Sprite(path){

}

Button::~Button() {}

void Button::Do()
{
}

void Button::Check(D3DXVECTOR2 pos)
{
	// x ���̿�, y ���̿� �����ϴ°�?
	if (this->pos.x <= pos.x && pos.x <= this->pos.x + Dpos.x)
		if (this->pos.y <= pos.y && pos.y <= this->pos.y + Dpos.y)
			Do();
}
