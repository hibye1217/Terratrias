#pragma once
#include "ButtonFunction.h"
#include "BaseScene.h"
class BFResume :
    public ButtonFunction
{
public:
    BaseScene* scene;

    BFResume(BaseScene* scene);    // ButtonFunction ��, Scene ��ü ���
    ~BFResume();               // �Ҹ��ڿ��� �� �ı��ϸ� �� ��������

    void Do();
};

