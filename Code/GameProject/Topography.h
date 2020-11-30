#pragma once
#include <string>
#include "Const.h"

class Topography
{
public:
	int type;
public:
	Topography();
	Topography(int type);
	int getType();
	virtual ~Topography();
	virtual bool canGo() = 0;
	//virtual void 
	Topography& operator = (const Topography&) = default;
};
