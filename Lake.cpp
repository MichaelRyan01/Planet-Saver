#include "Lake.h"
Lake::Lake(float lakeX, float lakeY)

{

	s_Sprite = Sprite(TileManager::GetTexture("graphics/lake.png"));

	s_Position.x = lakeX;
	s_Position.y = lakeY;

	s_Sprite.setPosition(s_Position);

}

FloatRect Lake::getPosition()

{

	return s_Sprite.getGlobalBounds();

}

Sprite Lake::getSprite()

{

	return s_Sprite;

}