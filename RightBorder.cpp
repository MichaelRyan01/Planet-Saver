#include "RightBorder.h"

//The constructor ask for specific coordinates 
RightBorder::RightBorder(float rightBorderX, float rightBorderY)

{
	//Sets the texture of the sprite from the file
	s_Sprite = Sprite(TileManager::GetTexture("graphics/subUI.png"));

	s_Position.x = rightBorderX;
	s_Position.y = rightBorderY;

	s_Sprite.setPosition(s_Position);
	s_Sprite.setRotation(90.0f);

}

FloatRect RightBorder::getPosition()

{
	//Returns the sprites position and global bounds
	return s_Sprite.getGlobalBounds();

}

Sprite RightBorder::getSprite()

{
	//returns the sprite to wherever its being called from
	return s_Sprite;

}