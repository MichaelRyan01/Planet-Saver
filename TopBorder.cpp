#include "TopBorder.h"

TopBorder::TopBorder(float X, float Y) {
	topB_Sprite = Sprite(TileManager::GetTexture("graphics/TopBorder.png"));
}

Sprite TopBorder::getSprite() {
	return topB_Sprite;
}

FloatRect TopBorder::getPosition() {
	return topB_Sprite.getGlobalBounds();
}