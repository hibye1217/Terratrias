#pragma once
#include "stdafx.h"
#include <cstdio>
#include "Jump.h"

Jump::Jump() : Item(Enum::JUMP, "Resources/Sprite/Big/Jump.png"), direction(-1) {}

Jump::~Jump() {}

void Jump::Render()
{
	Item::Render();
}

void Jump::useItem()
{
	// 방향 선택
	direction = -1;
	while (direction == -1)
	{
		inputManager->UpdateKeyState();
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
	}

	if (!canUseItem())
	{
		return;
	}
	User& user = manager.getUser();
	int userX = user.getX();
	int userY = user.getY();

	int nnx = userX + dx[direction] * 2;
	int nny = userY + dy[direction] * 2;
	
	user.setX(nnx);
	user.setY(nny);

	delete user.getInventory();
	user.setInventory(new None());
	//user.setInventory(item_list[Enum::NONE]);
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}

bool Jump::canUseItem()
{
	if (direction == -1)
	{
		return false;
	}
	int userX = manager.getUser().getX();
	int userY = manager.getUser().getY();
	int nx = userX + dx[direction];
	int ny = userY + dy[direction];
	int nnx = nx + dx[direction];
	int nny = ny + dy[direction];

	// 바로 앞은 못 가고, 2칸 앞은 갈 수 있어야 함
	if (!manager.isValidPoint(nx, ny) || !manager.isValidPoint(nnx, nny) ||
		manager.getCell(nx, ny).canGo() || !manager.getCell(nnx, nny).canGo())
	{
		return false;
	}
	return true;
}
