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
	//std::cout << "1. ��ư�� ������ ���� : " << this->pos.x << ", " << this->pos.x + Dpos.x << std::endl;
	//std::cout << "   ���콺�� x : " << pos.x << std::endl;
	//std::cout << "1. ��ư�� ��ܰ� �ϴ� : " << this->pos.y << ", " << this->pos.y + Dpos.y << std::endl;
	//std::cout << "   ���콺�� y : " << pos.y << std::endl;
	//std::cout << ((this->pos.x <= pos.x) && (pos.x <= this->pos.x + Dpos.x) && (this->pos.y <= pos.y) && (pos.y <= this->pos.y + Dpos.y)) << std::endl;

	// x ���̿�, y ���̿� �����ϴ°�?
	if (this->pos.x <= pos.x && pos.x <= this->pos.x + Dpos.x)
		if (this->pos.y <= pos.y && pos.y <= this->pos.y + Dpos.y)
			Do();
}
