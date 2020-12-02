#pragma once
#include "stdafx.h"
#include <cstdio>
#include "Jump.h"

Jump::Jump() : Item(Enum::JUMP), direction(-1) {}

Jump::~Jump() {}

void Jump::useItem()
{
	// ���� ����
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
	int userX = user.getX();
	int userY = user.getY();

	int nnx = userX + dx[direction] * 2;
	int nny = userY + dy[direction] * 2;
	
	user.setX(nnx);
	user.setY(nny);

	user.setInventory(item_list[Enum::NONE]);
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

	// �ٷ� ���� �� ����, 2ĭ ���� �� �� �־�� ��
	if (!manager.isValidPoint(nx, ny) || !manager.isValidPoint(nnx, nny) ||
		manager.getCell(nx, ny).canGo() || !manager.getCell(nnx, nny).canGo())
	{
		return false;
	}
	return true;
}
