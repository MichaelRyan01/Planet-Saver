#include "Lake.h"

//constructor using x and y
Lake::Lake(float lakeX, float lakeY)

{

	//set texture to lake
	s_Sprite = Sprite(TileManager::GetTexture("graphics/lake.png"));

	//set x value
	s_Position.x = lakeX;
	//set y value
	s_Position.y = lakeY;

	//set position of sprite
	s_Sprite.setPosition(s_Position);

}

//get position
FloatRect Lake::getPosition()

{

	//return position of sprite
	return s_Sprite.getGlobalBounds();

}

//get sprite
Sprite Lake::getSprite()

{

	//return sprite
	return s_Sprite;

}