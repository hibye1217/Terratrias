#pragma once
#include <cstdio>
#include "stdafx.h"
#include "Boost.h"

Boost::Boost() : Item(Enum::BOOST, "Resources/Sprite/Big/Boost.png"), direction(-1) {}

Boost::~Boost() {}

void Boost::useItem()
{
	// 방향 선택
	direction = -1;
	if (inputManager->GetKeyState('W') == KEY_DOWN || inputManager->GetKeyState('w') == KEY_DOWN)
	{
		direction = Enum::UP;
	}
	else if (inputManager->GetKeyState('A') == KEY_DOWN || inputManager->GetKeyState('a') == KEY_DOWN)
	{
		direction = Enum::LEFT;
	}
	else if (inputManager->GetKeyState('S') == KEY_DOWN || inputManager->GetKeyState('s') == KEY_DOWN)
	{
		direction = Enum::DOWN;
	}
	else if (inputManager->GetKeyState('D') == KEY_DOWN || inputManager->GetKeyState('d') == KEY_DOWN)
	{
		direction = Enum::RIGHT;
	}
	else
	{
		return;
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
	
	delete user.getInventory();
	user.setInventory(new None());
	//user.setInventory(item_list[Enum::NONE]);
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
