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

	// currentScene.objectList�� �� ���Ƽ� �ִ��� Ȯ���ϰ�, ������ ���� ������ �߰��ϼ�
	
	bool isExist = false;	// �̰� ¥�°� �����Ű����ϱ� ���߿� ����� ������ �ؾ߰���

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

