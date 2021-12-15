#include "Rocks.h"

Rocks::Rocks(float rockX, float rockY){
	r_Sprite = Sprite(TileManager::GetTexture("graphics/rock.png"));

	r_Position.x = rockX;
	r_Position.y = rockY;
	r_Sprite.setScale(0.1, 0.1);
	r_Sprite.setOrigin(25, 25);
	r_Sprite.setPosition(r_Position);
}

Sprite Rocks::getSprite() {
	return r_Sprite;
}