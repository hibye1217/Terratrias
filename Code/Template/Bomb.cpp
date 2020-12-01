#pragma once
#include "stdafx.h"
#include "Bomb.h"

Bomb::Bomb() : Item(Enum::BOMB) {}

Bomb::~Bomb() {}

void Bomb::useItem()
{
	if (!canUseItem())
	{
		return;
	}
	
	User& user = manager.getUser();
	int userX = user.getX();
	int userY = user.getY();
	for (int i = 0; i < 8; ++i)
	{
		int nx = userX + dx8[i];
		int ny = userY + dy8[i];
		if (!manager.isValidPoint(nx, ny))
		{
			continue;
		}
		Cell& cell = manager.getCell(nx, ny);
		if (cell.getItem()->getType() == Enum::KEY)
		{
			delete cell.getItem();
		}
		if (cell.getTopography()->getType() == Enum::HOLE)
		{
			delete cell.getTopography();
		}
		cell.setItem(item_list[Enum::NONE]);
		cell.setTopography(topo_list[Enum::SPACE]);
	}

	user.setInventory(item_list[Enum::NONE]);
	manager.setMoveCnt(manager.getMoveCnt() + 1);
}

bool Bomb::canUseItem()
{
	return true;
}
