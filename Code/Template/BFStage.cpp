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
	if (manager.getKeyCnt() != -1) {
		manager.finalize();
	}
	sceneManager->setPreparedScene(new StageScene(n));
}
