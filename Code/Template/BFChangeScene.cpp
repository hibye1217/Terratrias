#include "stdafx.h"
#include "BFChangeScene.h"

BFChangeScene::BFChangeScene(Scene* scene) : scene(scene) 
{
}

BFChangeScene::~BFChangeScene()
{
}

void BFChangeScene::Do()
{
	sceneManager->FadeChangeScene(scene);
}
