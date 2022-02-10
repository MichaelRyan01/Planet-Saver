#include "SubUI.h"
//The constructor ask for specific coordinates 
SubUI::SubUI(float subUIX, float subUIY)

{
	//Sets the texture of the sprite from the file
	s_Sprite = Sprite(TileManager::GetTexture("graphics/subUI.png"));

	s_Position.x = subUIX;
	s_Position.y = subUIY;

	s_Sprite.setPosition(s_Position);

}

FloatRect SubUI::getPosition()

{
	//Returns the sprites position and global bounds
	return s_Sprite.getGlobalBounds();

}

Sprite SubUI::getSprite()

{
	//returns the sprite to wherever its being called from
	return s_Sprite;

}