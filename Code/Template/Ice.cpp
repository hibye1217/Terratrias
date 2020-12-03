#pragma once
#include "stdafx.h"
#include "Ice.h"

Ice::Ice() : Topography(Enum::ICE) {}

Ice::~Ice() {}

void Ice::Render()
{
	Topography::Render();
}

bool Ice::canGo()
{
	return true;
}

void Ice::onArrived()
{
	if (manager.getLastDir() == -1)
	{
		return;
	}
	manager.setMoved(false);

	User& user = manager.getUser();
	int direction = manager.getLastDir();

	int userX = user.getX();
	int userY = user.getY();

	int nx = userX + dx[direction];
	int ny = userY + dy[direction];

	if (manager.isValidPoint(nx, ny) && manager.getCell(nx, ny).canGo())
	{
		user.setX(nx);
		user.setY(ny);
		manager.setMoved(true);
	}
}
