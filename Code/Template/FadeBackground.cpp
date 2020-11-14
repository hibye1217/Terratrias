#include "stdafx.h"
#include "FadeBackground.h"

FadeBackground::FadeBackground() {
	sprite = new Sprite("Resources/FadeBackground.png");
	AddChild(sprite);
	sprite->setPos(0, 0);
}

FadeBackground::~FadeBackground() {

}

void FadeBackground::Update(float dTime) {
	Object::Update(dTime);
}

void FadeBackground::Render() {
	Object::Render();
	sprite->Render();
}