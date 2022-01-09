#include "SideBorder.h"

SideBorder::SideBorder(float X, float Y) {
	sideB_Sprite = Sprite(TileManager::GetTexture("graphics/SideBorder.png"));
}

Sprite SideBorder::getSprite() {
	return sideB_Sprite;
}

FloatRect SideBorder::getPosition() {
	return sideB_Sprite.getGlobalBounds();
}