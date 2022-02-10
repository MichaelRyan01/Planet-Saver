#include "Rocks.h"

//The constructor ask for specific coordinates 
Rocks::Rocks(float rockX, float rockY){
	//Sets the texture of the sprite from the file
	r_Sprite = Sprite(TileManager::GetTexture("graphics/rock.png"));

	//The position is being set to the float coords
	r_Position.x = rockX;
	r_Position.y = rockY;

	//Scale, Origin and position
	r_Sprite.setScale(0.1, 0.1);
	r_Sprite.setOrigin(25, 25);
	r_Sprite.setPosition(r_Position);
}

Sprite Rocks::getSprite() {
	//returns the sprite to wherever its being called from
	return r_Sprite;
}

FloatRect Rocks::getPosition() {
	//Returns the sprites position and global bounds
	return r_Sprite.getGlobalBounds();
}

Vector2f Rocks::getCenter() {
	//returns the sprites centers
	return r_Position;
}

//returns the rock y coordinate
float Rocks::getY() {
	return rockY;
}

//returns the rock x coordinate
float Rocks::getX() {
	return rockX;
}

//returns the m_bottom variable
FloatRect Rocks::getBottom() {
	return m_bottom;
}

//returns the m_top variable
FloatRect Rocks::getTop() {
	return m_top;
}
//returns the m_left variable
FloatRect Rocks::getLeft() {
	return m_left;
}
//returns the m_right variable
FloatRect Rocks::getRight() {
	return m_right;
}