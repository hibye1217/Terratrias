#pragma once
#include "ButtonFunction.h"

class BFAdDelSprite :
    public ButtonFunction
{
public:
    std::list<Object*>& objectList;
    Object* object;

    BFAdDelSprite(std::list<Object*>& objectList, Object* object);    // ButtonFunction 중, Sprite의 추가/제거 기능
    ~BFAdDelSprite();

    void Do();  // 없다면 추가, 있다면 제거
};

