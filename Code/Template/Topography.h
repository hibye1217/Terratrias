#pragma once
#include <string>

class Topography
{
public:
	const std::string symbol;
public:
	Topography();
	Topography(const std::string& symbol);
	//Topography(Topography& topography);
	virtual bool canGo() = 0;
};

