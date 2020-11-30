#pragma once
#include <cstdio>
#include "Boost.h"

Boost::Boost() : Item(Enum::BOOST), direction(-1) {}

Boost::~Boost() {}

void Boost::useItem()
{
	// 방향 선택
	direction = -1;
	char ch = getchar();
	switch (ch)
	{
	case 'W':
	case 'w':
		direction = Enum::UP;
		break;
	case 'A':
	case 'a':
		direction = Enum::LEFT;
		break;
	case 'S':
	case 's':
		direction = Enum::DOWN;
		break;
	case 'D':
	case 'd':
		direction = Enum::RIGHT;
		break;
	}
	if (!canUseItem())
	{
		return;
	}

	User& user = manager.getUser();
	
	for (int i = 0; i < 5; ++i)
	{
		int userX = user.getX();
		int userY = user.getY();

		int nx = userX + dx[direction];
		int ny = userY + dy[direction];

		if (manager.isValidPoint(nx, ny) && manager.getCell(nx, ny).canGo())
		{
			user.setX(nx);
			user.setY(ny);
		}
		//if (manager.getCell(nx, ny).getTopography()->getType() == Enum::GLUE)
		//{
		//	break;
		//}
	}
	
	user.setInventory(item_list[Enum::NONE]);
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}

bool Boost::canUseItem()
{
	if (direction == -1)
	{
		return false;
	}
	int userX = manager.getUser().getX();
	int userY = manager.getUser().getY();
	int nx = userX + dx[direction];
	int ny = userY + dy[direction];

	if (!manager.isValidPoint(nx, ny) || !manager.getCell(nx, ny).canGo())
	{
		return false;
	}
	return true;
}
