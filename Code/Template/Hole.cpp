#pragma once
#include "stdafx.h"
#include "Hole.h"

Hole::Hole() : Hole(-1) {}

Hole::Hole(int id) : Topography(Enum::HOLE), id(id) {}

Hole::~Hole() {}

int Hole::getId() 
{
    return id;
}

bool Hole::canGo() 
{
	return true;
}
