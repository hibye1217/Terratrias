#pragma once
#include "ButtonFunction.h"

class BFAdDelSprite :
    public ButtonFunction
{
public:
    Scene* currentScene;
    Object* object;

    BFAdDelSprite(Scene* currentScene, Object* object);    // ButtonFunction ��, Sprite�� �߰�/���� ���
    ~BFAdDelSprite();

    void Do();  // ���ٸ� �߰�, �ִٸ� ���Ÿ� �����ؾ���
};

