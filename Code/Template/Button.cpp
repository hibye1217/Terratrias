#include "stdafx.h"
#include "Button.h"

Button::Button() : Sprite("Resources/Danmaku_1.png") {}

Button::Button(const char* path) : Sprite(path){

}

Button::~Button() {}

void Button::Do()
{
	for (auto& bf : bfList) 
		bf->Do();
}

void Button::setDpos(D3DXVECTOR2 pos)
{
	this->Dpos - Dpos;
}

void Button::setDpos(int dx, int dy)
{
	this->Dpos.x = dx;
	this->Dpos.y = dy;
}

void Button::Check(D3DXVECTOR2 pos)
{
	//std::cout << "1. 버튼의 좌측과 우측 : " << this->pos.x << ", " << this->pos.x + Dpos.x << std::endl;
	//std::cout << "   마우스의 x : " << pos.x << std::endl;
	//std::cout << "1. 버튼의 상단과 하단 : " << this->pos.y << ", " << this->pos.y + Dpos.y << std::endl;
	//std::cout << "   마우스의 y : " << pos.y << std::endl;
	//std::cout << ((this->pos.x <= pos.x) && (pos.x <= this->pos.x + Dpos.x) && (this->pos.y <= pos.y) && (pos.y <= this->pos.y + Dpos.y)) << std::endl;

	// x 사이에, y 사이에 존재하는가?
	if (this->pos.x <= pos.x && pos.x <= this->pos.x + Dpos.x)
		if (this->pos.y <= pos.y && pos.y <= this->pos.y + Dpos.y)
			Do();
}
