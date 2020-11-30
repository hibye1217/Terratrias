#pragma once
#include <string>

class Topography
{
public:
	int type;
public:
	Topography();
	Topography(int type);
	virtual ~Topography();
	int getType();
	virtual void onArrived();
	virtual bool canGo() = 0;
	Topography& operator = (const Topography&) = default;
};
