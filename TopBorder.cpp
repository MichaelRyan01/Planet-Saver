#include "TopBorder.h"

//The constructor ask for specific coordinates 
TopBorder::TopBorder(float X, float Y) {
	//Sets the texture of the sprite from the file
	topB_Sprite = Sprite(TileManager::GetTexture("graphics/TopBorder.png"));
}

Sprite TopBorder::getSprite() {
	//returns the sprite to wherever its being called from
	return topB_Sprite;
}

FloatRect TopBorder::getPosition() {
	//Returns the sprites position and global bounds
	return topB_Sprite.getGlobalBounds();
}