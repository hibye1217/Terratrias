#pragma once
#include "Sprite.h"
#include <d3dx9.h>
#include "ButtonFunction.h"


class Button :
    public Sprite
{
public:
    D3DXVECTOR2 Dpos;
    std::list<ButtonFunction*> bfList;  // ButtonFunction List

    Button();
    Button(const char* path);   // Button �� ���콺�� ���� ��ư�� �������� ���θ� Ȯ���ϰ�, ButtonFunction�� �ҷ��´�
    ~Button();

    void Check(D3DXVECTOR2 pos);
    void Do();

};

