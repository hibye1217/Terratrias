#include "stdafx.h"
#include "BFResume.h"

BFResume::BFResume(BaseScene* scene) : scene(scene)
{
}

BFResume::~BFResume()
{
	SAFE_DELETE(scene);
}

void BFResume::Do()
{
	sceneManager->ChangeButtonList(scene);
	scene->setIsSubSceneOn();
}
