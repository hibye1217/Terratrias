#pragma once
#include "stdafx.h"
#include "Hole.h"

Hole::Hole() : Hole(-1) {}

Hole::Hole(int id)
	: id(id), Topography(Enum::HOLE, id) {

}

Hole::~Hole() {}

void Hole::Render()
{
	Topography::Render();
}

int Hole::getId() 
{
    return id;
}

bool Hole::canGo() 
{
	return true;
}
