#pragma once
#include <vector>
#include <string>
#include "Cell.h"
#include "User.h"
#include "Hole.h"
#include "Key.h"

class Manager
{
private:
	std::vector<std::vector<Cell>> map;
	int height, width;
	int moveCnt, limitCnt, keyCnt;
	User user;
	float scaleRatio;
	int lastDir;
	bool moved;
public:
	Manager();
	~Manager();

	Cell& getCell(int x, int y);
	void setCell(int x, int y, Cell& cell);
	int getHeight();
	int getWidth();
	//Item& getCellItem(int x, int y);
	//void setCellItem(int x, int y, Item& cell);
	//Topography& getCellTopography(int x, int y);
	//void setCellTopography(int x, int y, Topography& topography);
	User& getUser();
	bool isValidPoint(int x, int y);

	int getMoveCnt();
	void setMoveCnt(int moveCnt);
	int getLimitCnt();
	void setLimitCnt(int limitCnt);
	int getKeyCnt();
	void setKeyCnt(int keyCnt);
	void setScaleRatio(float);
	float getScaleRatio();
	void setLastDir(int dir);
	int getLastDir();
	void setMoved(bool moved);
	bool getMoved();
	void initialize(std::string filename);
	void finalize();
};
