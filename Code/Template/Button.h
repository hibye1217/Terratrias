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
    std::list<ButtonFunction*> hbfList; // Hovering ButtonFunction List

    Button();
    Button(const char* path);   // Button 은 마우스가 현재 버튼을 눌렀는지 여부를 확인하고, ButtonFunction을 불러온다
    ~Button();

    void setDpos(D3DXVECTOR2 pos);
    void setDpos(int dx, int dy);

    void Check(D3DXVECTOR2 pos);
    void hoveringCheck(D3DXVECTOR2 pos);

    void Do();                  // 
    void hoveringDo();

};

