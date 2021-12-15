#include "Waste.h"
Waste::Waste(float wasteX, float wasteY){

	w_Sprite = Sprite(TileManager::GetTexture("graphics/oilspill.png"));

	w_Position.x = wasteX;
	w_Position.y = wasteY;
	w_Sprite.setScale(0.5, 0.5);
	w_Sprite.setOrigin(125, 125);
	w_Sprite.setPosition(w_Position);
}

Sprite Waste::getSprite() {
	return w_Sprite;
}