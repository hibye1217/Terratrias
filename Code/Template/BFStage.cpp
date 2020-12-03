#include "stdafx.h"
#include "BFStage.h"

BFStage::BFStage(int a) : n(a)
{
}

BFStage::~BFStage()
{
}

void BFStage::Do()
{
	if (manager.getCell(0, 0).getTopography()) {
		manager.finalize();
	}
	sceneManager->setPreparedScene(new StageScene(n));
}
