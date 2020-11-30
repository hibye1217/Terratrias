#pragma once
#include <string>

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
	Topography& operator = (const Topography&) = default;
};
