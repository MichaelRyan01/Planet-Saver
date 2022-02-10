#include "SideBorder.h"

//The constructor ask for specific coordinates 
SideBorder::SideBorder(float X, float Y) {
	//Sets the texture of the sprite from the file
	sideB_Sprite = Sprite(TileManager::GetTexture("graphics/SideBorder.png"));
}

Sprite SideBorder::getSprite() {
	//returns the sprite to wherever its being called from
	return sideB_Sprite;
}

FloatRect SideBorder::getPosition() {
	//Returns the sprites position and global bounds
	return sideB_Sprite.getGlobalBounds();
}