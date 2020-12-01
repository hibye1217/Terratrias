#include "stdafx.h"
#include "BFAdDelSprite.h"

BFAdDelSprite::BFAdDelSprite(std::list<Object*>& objectList, Object* object) : objectList(objectList), object(object)
{
}

BFAdDelSprite::~BFAdDelSprite()
{
}

void BFAdDelSprite::Do()
{

	// currentScene.objectList를 싹 돌아서 있는지 확인하고, 있으면 삭제 없으면 추가하셈
	
	bool isExist = false;	// 이거 짜는거 터질거같으니까 나중에 고수들 있을때 해야겠음

	for (auto& object : objectList) {
		if (object == this->object)
			isExist = true;
		//std::cout << "Iter : " << isExist << std::endl;
	}
	if (isExist)
		objectList.remove(object);
	else {
		objectList.push_back(object);
		object->setParent(nullptr);
	}

	//std::cout << "Do()" << std::endl;
}

