#pragma once
#include "ButtonFunction.h"

class BFAdDelSprite :
    public ButtonFunction
{
public:
    std::list<Object*>& objectList;
    Object* object;

    BFAdDelSprite(std::list<Object*>& objectList, Object* object);    // ButtonFunction ��, Sprite�� �߰�/���� ���
    ~BFAdDelSprite();

    void Do();  // ���ٸ� �߰�, �ִٸ� ����
};

