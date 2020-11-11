#pragma once

#include "Object.h"

class Font : public Object {
private:
	LPD3DXFONT pFont;
	D3DXFONT_DESC desc;
	char* str;

	D3DCOLOR color;

public:
	Font();
	~Font();

	void Render();
	void setText(const char* text);
	
	void setPos(int x, int y);
	void setHeight(int height);
	void setWidth(int width);
};