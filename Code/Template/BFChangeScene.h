#pragma once
#include "ButtonFunction.h"

class BFChangeScene :
    public ButtonFunction
{
public:
    Scene* scene;

    BFChangeScene(Scene* scene);    // ButtonFunction ��, Scene ��ü ���
    ~BFChangeScene();               // �Ҹ��ڿ��� �� �ı��ϸ� �� ��������

    void Do();
};

