#pragma once
#include "stdafx.h"
#include "ButtonFunction.h"
class BFFinalize :
    public ButtonFunction
{
public:
    BFFinalize();    // ButtonFunction ��, Scene ��ü ���
    ~BFFinalize();               // �Ҹ��ڿ��� �� �ı��ϸ� �� ��������

    void Do();
};

