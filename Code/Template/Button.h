#pragma once
#include "Sprite.h"
#include <d3dx9.h>


class Button :
    public Sprite
{
public:
    D3DXVECTOR2 Dpos;

    Button();
    Button(const char* path);
    ~Button();
};

